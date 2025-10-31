-- Active: 1761280113892@@127.0.0.1@3306@companyinfo
SHOW DATABASES;
DROP DATABASE CompanyInfo;
CREATE DATABASE IF NOT EXISTS CompanyInfo;
USE CompanyInfo;

CREATE TABLE Department(
    d_id INT PRIMARY KEY NOT NULL UNIQUE,
    d_name VARCHAR(20) NOT NULL UNIQUE,
    `function` VARCHAR(20),
    address VARCHAR(30)
);

CREATE TABLE employee(
    id INT PRIMARY KEY NOT NULL UNIQUE,
    name VARCHAR(20) NOT NULL,
    sex ENUM('男','女') NOT NULL,
    age INT,
    d_id INT NOT NULL,
    salary FLOAT,
    card VARCHAR(18) UNIQUE,
    address VARCHAR(50),
    FOREIGN KEY (d_id) REFERENCES Department(d_id)
);

INSERT INTO Department VALUES
    (1, '研发部', '产品开发', '北京市海淀区'),
    (2, '人事部', '人员管理', '北京市朝阳区'),
    (3, '财务部', '财务核算', '北京市西城区');

INSERT INTO employee VALUES
    (1, '张三', '男', 22, 1, 8000, '110101200101011234', '北京市海淀区'),
    (2, '李四', '女', 19, 2, 6500, '110101200401015678', '北京市朝阳区'),
    (3, '王五', '男', 25, 1, 9000, '110101199801012345', '北京市丰台区'),
    (4, '赵六', '女', 28, 3, 7500, '110101199501015678', '北京市西城区'),
    (5, '钱七', '男', 18, 2, 5000, '110101200501018901', '北京市海淀区');

CREATE INDEX index_dname ON Department(d_name);
CREATE INDEX index_name ON employee(name);
CREATE INDEX index_name2 ON employee(name(2));
EXPLAIN SELECT * FROM employee WHERE name LIKE '张%';
EXPLAIN SELECT * FROM employee USE INDEX FOR JOIN(index_name2) WHERE NAME LIKE '张%';
CREATE FULLTEXT INDEX fullindex_name ON employee(name);
CREATE INDEX index_ageadress ON employee(age,address);
ALTER TABLE employee ADD UNIQUE INDEX index_id(id ASC);
SHOW INDEX FROM employee;
SHOW INDEX FROM department;
DROP INDEX index_dname ON Department;
DROP INDEX index_name ON employee;
CREATE VIEW employee_view(id,name,sex,address)
AS SELECT id,name,sex,address FROM
employee WHERE age>20
WITH LOCAL CHECK OPTION;
DESC employee_view;
SHOW CREATE VIEW employee_view;
SELECT * FROM employee_view;
ALTER VIEW employee_view(id,name,sex,address)
AS SELECT id,name,sex,address FROM
employee WHERE age<20
WITH LOCAL CHECK OPTION;
UPDATE employee_view SET sex='女' WHERE id=3;
DROP VIEW IF EXISTS employee_view;
CREATE VIEW employee_view2
AS SELECT A.id,A.name,A.sex,A.address,B.d_name
FROM employee A
LEFT JOIN Department B ON A.d_id=B.d_id
WHERE A.address LIKE '北京%';
CREATE VIEW employee_view3(员工名,姓名, 性别,家庭住址,部门名)
AS SELECT
    A.id,A.name,A.sex,A.address,B.d_name
FROM employee A
LEFT JOIN Department B ON A.d_id=B.d_id
WHERE A.address LIKE '北京%';