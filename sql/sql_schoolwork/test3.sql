CREATE DATABASE IF NOT EXISTS CompanyInfo DEFAULT CHARSET utf8;
USE CompanyInfo;
CREATE TABLE IF NOT EXISTS Department
(
  d_id INT PRIMARY KEY,
  d_name varchar(20) NOT NULL,
  `function` VARCHAR(20),
  address VARCHAR(30)
);
CREATE TABLE IF NOT EXISTS employee
(
  id INT PRIMARY KEY,
  NAME VARCHAR(20) NOT NULL,
  sex VARCHAR(4) NOT NULL,
  age INT,
  d_id INT NOT NULL,
  salary FLOAT,
  address VARCHAR(50),
  FOREIGN KEY (d_id) REFERENCES Department(d_id)
);
INSERT INTO Department VALUES
  (1001, '人事部', '人事管理', '北京'),
  (1002, '科研部', '研发产品', '广州'),
  (1003, '生产部', '产品生产', '天津'),
  (1004, '销售部', '产品销售', '上海');
INSERT INTO employee VALUES
  (8001, '韩鹏', '男', 25, 1002, 9000, '北京市海淀区'),
  (8002, '张峰', '男', 26, 1001, 7500, '北京市昌平区'),
  (8003, '欧阳', '男', 20, 1003, 6000, '湖南省永州市'),
  (8004, '王武', '男', 30, 1001, 8000, '北京市顺义区'),
  (8005, '欧阳宝贝', '女', 21, 1002, 7000, '北京市昌平区'),
  (8006, '呼延', '男', 28, 1003, 6800, '天津市南开区'),
  (8007, '刘恒', '男', 40, 1001, 6800, '北京市顺义区');
INSERT INTO employee VALUES
  (8888,'万春宏','男',18,1002,8888,'北京市朝阳区');
UPDATE Department SET address ='北京' WHERE d_id = 1002;
UPDATE employee SET salary=8500 WHERE NAME = '欧阳';
DELETE FROM employee WHERE NAME = '刘恒';
SELECT * FROM employee;
SELECT * FROM employee ORDER BY id LIMIT 3,2;
SELECT d_id,d_name,'function' FROM Department;
SELECT e.* FROM employee e JOIN
(
  SELECT d_id FROM  Department WHERE d_name IN ('人事部','科研部')
)dept ON e.d_id = dept.d_id;
SELECT * FROM employee WHERE age >= 25 AND age <= 30;
SELECT d_id,COUNT(*) AS emp_count FROM employee GROUP BY d_id;
SELECT d_id,MAX(salary) AS max_salary FROM employee GROUP BY d_id;
SELECT d.*,e.* FROM Department d LEFT JOIN employee e ON d.d_id = e.d_id;
SELECT d_id ,SUM(salary) AS total_salary FROM employee GROUP BY d_id;
SELECT * FROM employee ORDER BY salary DESC;  
SELECT d_id FROM Department UNION SELECT d_id FROM employee;
SELECT NAME,age,address FROM employee WHERE address LIKE '北京市%';
SELECT d_id,
  SUM(CASE WHEN sex = '男' THEN 1 ELSE 0 END) AS male_count,
  SUM(CASE WHEN sex = '女' THEN 1 ELSE 0 END) AS female_count
FROM employee GROUP BY d_id;
SELECT 
  e.id AS 员工号,
  e.name AS 姓名,
  e.sex AS 性别,
  d.d_name AS 部门名称,
  e.address AS 家庭住址
FROM employee e JOIN Department d ON e.d_id =d.d_id; 
SELECT * FROM employee;