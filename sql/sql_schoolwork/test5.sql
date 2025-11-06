-- Active: 1762253198320@@127.0.0.1@3306@supermarket
CREATE DATABASE IF NOT EXISTS supermarket;
USE supermarket;
DROP TABLE food;

CREATE TABLE IF NOT EXISTS food(
    Foodid INT PRIMARY KEY AUTO_INCREMENT,
    Name VARCHAR(20) NOT NULL,
    Company VARCHAR(30) NOT NULL,
    Buying_price FLOAT NOT NULL,
    Product_date DATE,
    expiring_date DATE,
    address VARCHAR(50)
);

CREATE TABLE IF NOT EXISTS sales(
    id INT PRIMARY KEY AUTO_INCREMENT,
    foodid INT NOT NULL,
    price INT NOT NULL,
    amount INT NOT NULL,
    sale_date DATETIME NOT NULL,
    FOREIGN KEY(foodid) REFERENCES food(Foodid)
)

INSERT INTO food(Foodid,Name,Company,Buying_price,Product_date,expiring_date,address) VALUES
    (1001,'QQ饼干','QQ饼干厂',12,'2020-12-12','2021-12-11','北京'),
    (1002,'MN牛奶','MN牛奶厂',5.5,'2021-06-01','2022-05-31','河北'),
    (1003,'EE果冻','EE果冻厂',4.5,'2021-06-07','2021-12-06','北京'),
    (1004,'FF咖啡','FF咖啡厂',20,'2019-11-01','2021-10-31','天津'),
    (1005,'GG奶糖','GG食品厂',15,'2018-10-29','2021-10-28','广东'),
    (1006,'GG牛奶','GG食品厂',4.5,'2019-10-25','2021-10-24','广东');
SELECT * FROM food;

INSERT INTO sales (foodid, price, amount, sale_date) VALUES
    (1001,15,2,'2024-05-20 09:30:00'),
    (1002,7,5,'2024-05-20 10:15:00'),
    (1003,6,10,'2024-05-20 11:20:00'),
    (1004,25,3,'2024-05-20 14:40:00'),
    (1005,18,4,'2024-05-20 16:00:00'),
    (1006,6,8,'2024-05-20 18:30:00'),
    (1001,15,3,'2024-05-10 09:00:00'),
    (1002,7,4,'2024-05-12 10:00:00'),
    (1003,6,6,'2024-05-15 11:00:00'),
    (1004,25,2,'2024-05-18 14:00:00'),
    (1005,18,5,'2024-05-19 15:00:00'),
    (1006,6,10,'2024-05-05 16:00:00');
SELECT * FROM sales;

DELIMITER //
CREATE PROCEDURE Get_Company_food(IN p_company VARCHAR(30))
BEGIN 
    SELECT Foodid,Name,Buying_price,Product_date,expiring_date
        FROM food
        WHERE Company=p_company;
END //
DELIMITER;

DELIMITER //
CREATE PROCEDURE Get_Sales()
BEGIN
    SELECT '当天总销售额' AS 统计项,SUM(price*amount) AS 总金额 
        FROM sales
        WHERE DATE(sale_date)=CURDATE();
    SELECT '当天每种食品销售额' AS 统计项,f.Foodid,f.Name,SUM(s.price*s.amount) AS 销售金额
        FROM sales s JOIN food f ON s.foodid=f.Foodid
        WHERE DATE(s.sale_date)=CURDATE()
        GROUP BY f.Foodid,f.Name;
    SELECT '当月每种食品销售额' AS 统计项,f.Foodid,f.Name,SUM(s.price*s.amount) AS 销售金额
        FROM sales s JOIN food f ON s.foodid=f.Foodid
        WHERE YEAR(s.sale_date)=YEAR(CURDATE()) AND MONTH(s.sale_date)=MONTH(CURDATE())
        GROUP BY f.Foodid,f.Name;
END //
DELIMITER;

DELIMITER //
CREATE PROCEDURE Pfood_price_count(IN price_info1 FLOAT,IN price_info2 FLOAT,OUT count INT)
BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE tmp_price FLOAT;
    DECLARE food_cursor CURSOR FOR
        SELECT Buying_price 
        FROM food
        WHERE Buying_price BETWEEN price_info1 AND price_info2 AND expiring_date>CURDATE();
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done=1;
    SET count=0;
    SET @avgprice=0;
    SET @total_price=0;
    OPEN food_cursor;
    cursor_loop:LOOP
        FETCH food_cursor INTO tmp_price;
        IF done=1 THEN LEAVE cursor_loop;
        END IF;
        SET count=count+1;
        SET @total_price=@total_price+tmp_price;
    END LOOP cursor_loop;
    CLOSE food_cursor;
    IF count>0 THEN
        SET @avgprice=@total_price/count;
    END IF;
END //
DELIMITER;

CALL `Get_Company_food`('GG食品厂');
CALL `Get_Sales`();
CALL `Pfood_price_count`(5,20,@food_count);
SELECT @food_conut AS 符合条件食品数量,
    @avgprice AS 平均进货单价;