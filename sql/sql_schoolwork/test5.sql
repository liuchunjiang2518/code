-- Active: 1761280113892@@127.0.0.1@3306@supermarket
CREATE DATABASE IF NOT EXISTS supermarket;
USE supermarket;
DROP TABLE food;

CREATE TABLE IF NOT EXISTS food(
    Foodid INT PRIMARY KEY AUTO_INCREMENT,
    Name VARCHAR(20) NOT NULL,
    Company VARCHAR(30) NOT NULL,
    Fuying_price FLOAT NOT NULL,
    Product_date DATE,
    expiring_date DATE,
    address VARCHAR(50)
);

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
        FROM sales s JOIN food f ON s.foodid=f.`Foodid`
        WHERE DATE(s.sale_date)=CURDATE()
        GROUP BY f.Foodid,f.Name;
    SELECT '当月每种食品销售额' AS 统计项,f.Foodid,f.Name,SUM(s.price*s.amount) AS 销售金额
        FROM sales s JOIN food f ON s.foodid=f.Foodid
        WHERE YEAR(s.sale_date)=YEAR(CURDATE()) AND MONTH(s.sale_date)=MONTH(CURDATE())
        GROUP BY f.Foodid,f.Name;
END //
DELIMITER;
