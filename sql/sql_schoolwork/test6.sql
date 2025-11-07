CREATE DATABASE Companyinfo;
USE Companyinfo;

CREATE TABLE product(
    id INT NOT NULL PRIMARY KEY,
    NAME VARCHAR(20) NOT NULL,
    `function` VARCHAR(50),
    company VARCHAR(20) NOT NULL,
    address VARCHAR(50)
);

CREATE TABLE operate(
    op_id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    op_name VARCHAR(200) NOT NULL,
    op_time DATETIME NOT NULL,
    op_desc VARCHAR(100)
);

CREATE TRIGGER Tproduct_bf_insert
BEFORE INSERT ON product
FOR EACH ROW
INSERT INTO operate(op_name,op_time,op_desc) VALUES(
    USER(),
    NOW(),
    CONCAT('新增产品:',NEW.NAME,',厂商:',NEW.company,',地址:',NEW,address)
);

CREATE TRIGGER Tproduct_af_update
AFTER UPDATE ON product
FOR EACH ROW
INSERT INTO operate(op_name,op_time,op_desc) VALUES(
    USER(),
    NOW(),
    CONCAT('修改产品:',OLD.NAME,',原地址:',OLD.address,',新地址:',NEW.address)
);

CREATE TRIGGER Tproduct_af_del
AFTER DELETE ON product
FOR EACH ROW
INSERT INTO operate(op_name,op_time,op_desc) VALUES(
    USER(),
    NOW(),
    CONCAT('删除产品:',OLD.NAME,',厂商:',OLD.company)
);