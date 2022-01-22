.header on
.width 0 0
.mode column
create table Branch(
  Branch_id int primary key,
  Branch_name varchar(30),
  Branch_address varchar(30)
);

insert into Branch values
  (101,"Branch1","Pune"),
  (102,"Branch2","Satara"),
  (103,"Branch3","Nagar"),
  (104,"Branch4","Pimpari"),
  (105,"Branch5","Kolhapur")  
  ;


select * from Branch;

create table Customer(
  Customer_id int primary key,
  Customer_name varchar(40),
  Contact_number number,
  Age int,
  Cust_address varchar(20),
  Cust_city varchar(20),
  Branch_id int,foreign key (Branch_id) references Branch(Branch_id)
);

insert into Customer values
(1,"Gajanan Shinde",9876543210,22,"Karjat","Karjat",101),
(2,"Aditya Bhosale",9865643210,21,"Rampur","Aurangabad",103),
(3,"Rahul Barate",9895543210,24,"Otur","Pune",101),
(4,"Krushna Kadam",9895539210,25,"Bhigvan","Satara",104),
(5,"Mahesh Jadhav",9896539210,34,"Sule","Nagpur",105),
(6,"Abhishek Asawale",9895536210,40,"Ambegoav","Pune",104),
(7,"Jyostna Mindhe",9895539780,21,"Jamkhed","Karjat",105),
(8,"Priya Mishra",9895545210,24,"Rajuri","Solapur",105);
.print Database is created
.print
.print Table data with group by clause is:
select * from Customer group by "Customer_name";

.print
.print
.print Select query for age >=25 with order by clause: 
select * from Customer where Age>=25 order by "Age";

.print
.print
.print Example of AND: 
select Customer_name,Contact_number from Customer where Cust_city="Pune" AND age>30;


.print
.print
.print Example of OR: 
select * from Customer where Cust_city="Nagpur" OR Cust_city="Solapur";


.print
.print
.print Example of AND,OR combine: 
select * from Customer where Cust_address="Bhigvan" OR Age<=22;

.print
.print
.print Example of NOT: 
select * from Customer where NOT Branch_id=104;

.print
.print
.print like clause: 
select * from Customer where Customer_name like "A%";

.print
.print
.print Example of Count: 
select count(*) from Customer where Age>27;

.print
.print
.print Example of max: 
select * from customer where age=(select max(age) from Customer);

.print
.print
.print Example of min: 
select Customer_name from customer where age=(select min(age) from Customer);

.print
.print
.print Example of avg: 
select avg(age) from customer;

.print
.print
.print Example of multiple group by clause: 
select * from Customer group by "Customer_name","Cust_city";


.print
.print
.print Update operation 
.print
.print
.print Before update


select * from Customer where Customer_id=8;



Update Customer set Age=35 where Customer_id=8;
.print
.print
.print  after update
select * from Customer;

.print
.print
.print delete operation 
.print
.print
.print Before delete
select * from Customer;


delete from Customer where Cust_address="Sule";



.print
.print
.print  after delete
select * from Customer;

.print
.print
.print  Inner Join
select Customer.Customer_id,customer.Customer_name,Branch.Branch_name from Customer Inner Join Branch on Branch.Branch_id=Customer.Branch_id;

.print
.print
.print  left Join
select Customer.Customer_id,customer.Customer_name,Branch.Branch_name from customer left join Branch on Customer.Branch_id=Branch.Branch_id;