.header on
.width 0 0
.mode column
PRAGMA foreign_keys = ON;
CREATE TABLE Customer(
  Customer_id int primary key,
  Customer_name varchar(40) NOT NULL,
  Contact_number number,
  Age int CHECK (AGE>0),
  Cust_address varchar(20),
  Cust_city varchar(20)
);

INSERT INTO Customer VALUES
(11,"Gajanan Shinde",9876543210,22,"Karjat","Karjat"),
(12,"Aditya Bhosale",9865643210,21,"Rampur","Aurangabad"),
(13,"Rahul Barate",9895543210,24,"Otur","Pune"),
(14,"Krushna Kadam",9895539210,25,"Bhigvan","Satara"),
(15,"Mahesh Jadhav",9896539210,34,"Sule","Nagpur"),
(16,"Abhishek Asawale",9895536210,40,"Ambegoav","Pune"),
(17,"Jyostna Mindhe",9895539780,21,"Jamkhed","Karjat"),
(18,"Priya Mishra",9895545210,24,"Rajuri","Solapur");


.print
.print CUSTOMER TABLE DATA
SELECT * FROM Customer;


CREATE TABLE ORDERS(
  Order_id int primary key,
  Amount money NOT NULL,
  Order_date date,
  Customer_id int ,
  foreign key (Customer_id) references Customer(Customer_id)
);


INSERT INTO ORDERS VALUES
(1256,7800,"20-01-2021",11),
(1260,9,"01-01-2021",11),
(1265,40,"19-01-2022",12),
(1278,904,"01-01-2021",12),
(1323,82,"20-08-2021",11),
(1307,478,"25-05-2021",13),
(1333,9000,"13-05-2021",13),
(1452,9000,"27-12-2021",14),
(1560,675,"01-01-2022",15),
(1580,50,"05-11-2021",16)
;


.print
.print
.print ORDERS TABLE DATA

SELECT * FROM ORDERS;


.print
.print
.print UPDATING DATA Amount BY 20% FOR CUSTOMER CITY IS "Pune"

UPDATE ORDERS SET Amount=Amount*20
WHERE Customer_id IN (SELECT Customer_id FROM CUSTOMER WHERE Cust_city="Pune");

.print
.print
.print UPDATED DATA Amount BY 20% FOR CUSTOMER CITY IS "Pune"

SELECT * FROM ORDERS;


.print
.print
.print DELETE OPERATION DELETE ORDERS RECORDS WHICH Amount <50

DELETE FROM ORDERS WHERE Amount<50;

.print
.print
.print AFTER DELETION DATA IS

SELECT * FROM ORDERS;


.print
.print
.print GROUP BY IN CUSTOMER

SELECT * FROM CUSTOMER GROUP BY  Customer_name;

.print
.print
.print ORDER BY IN ORDERS
SELECT * FROM ORDERS ORDER BY Amount;


.print
.print
.print HAVING CAUSE IN CUSTOMER

SELECT * FROM CUSTOMER GROUP BY Age HAVING (AGE>30);

.print
.print
.print CUSTOMER DETAILS OF MAXIMUM Amount

SELECT * FROM CUSTOMER WHERE Customer_id =(SELECT Customer_id FROM ORDERS WHERE Amount=(SELECT MAX(Amount) FROM ORDERS));

.print
.print
.print CUSTOMER DETAILS OF MINIMUM Amount OF ORDERS

SELECT CUSTOMER.Customer_id,CUSTOMER.Customer_name,ORDERS.Amount FROM CUSTOMER ,ORDERS 
WHERE CUSTOMER.Customer_id=ORDERS.Customer_id AND ORDERS.Amount=(SELECT MIN(Amount) FROM ORDERS);


.print
.print
.print COUNT CUSTOMERS AGE>30

SELECT COUNT(Customer_id) FROM CUSTOMER WHERE Age>30;

.print
.print
.print CALCULATE TOTAL Amount OF ORDERS OF CUSTOMER ID 11

SELECT  SUM(Amount) FROM ORDERS WHERE Customer_id=11;

.print
.print
.print CALCULATE AVERAGE Amount OF ORDERS OF CUSTOMER ID 11
SELECT  AVG(Amount) FROM ORDERS WHERE Customer_id=11;


.print
.print
.print EXAMPLE OF AND
SELECT * FROM ORDERS WHERE Amount>50 AND Amount<3000;

.print
.print
.print EXAMPLE OF OR
SELECT * FROM CUSTOMER WHERE Age>50 OR Cust_city="Pune";

.print
.print
.print EXAMPLE OF LIKE --SHOWS CUSTOMER DETAILS OF HAVING 2ND CHARACTER IS 'A'
SELECT * FROM CUSTOMER WHERE Customer_name LIKE "_A%";

.print
.print
.print EXAMPLE OF JOIN
SELECT CUSTOMER.Customer_name , ORDERS.Order_date , ORDERS.Amount FROM CUSTOMER INNER JOIN ORDERS ON CUSTOMER.Customer_id=ORDERS.Customer_id;
