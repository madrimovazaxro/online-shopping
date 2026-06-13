# online-shopping
````md
# Online Shopping System (C++ OOP Project)

## Project Description

This project is a console-based **Online Shopping System** developed in **C++** using **Object-Oriented Programming (OOP)** principles and **file handling**.

The system allows:

- Admins to manage products and orders
- Customers to browse products, add items to cart, and place orders
- Data persistence using text files

---

# OOP Concepts Used

This project demonstrates the following OOP concepts:

- Encapsulation
- Inheritance
- Runtime Polymorphism
- Abstraction
- Composition
- Constructors & Destructors
- Vectors and Object Collections

---

# Technologies Used

- C++
- File Handling
- STL Vector
- Object-Oriented Programming

---

# System Roles

## 1. Admin

Admin can:

- View all products
- Add products
- Edit products
- Delete products
- View customer orders

---

## 2. Customer

Customer can:

- Login
- Browse products
- Add products to cart
- Remove products from cart
- View cart
- Checkout
- View order history

---

# Project Structure

## Classes

### User
Base abstract class for all users.

### Admin
Inherited from User.
Handles product and order management.

### Customer
Inherited from User.
Handles shopping cart and checkout system.

### Product
Stores product information.

### Cart
Stores products and quantities selected by customer.

### Order
Stores completed order information.

### Database
Handles saving/loading data from files.

---

# Files Used

| File | Purpose |
|------|----------|
| users.txt | Stores user login data |
| products.txt | Stores products |
| orders.txt | Stores customer orders |

---

# Example users.txt

```txt
1 ali 1234 customer
2 admin 5678 admin
````

---

# Example products.txt

```txt
1 Laptop Electronics 2500 5
2 Mouse Accessories 50 20
```

---

# Features

* Role-based login system
* Product management
* Shopping cart system
* Order history
* Automatic stock updates
* File-based database
* Error handling using try-catch
* Input validation

---

# Main Functionalities

## Login System

Users login using:

* username
* password

The system checks credentials from `users.txt`.

---

## Product Management

Admin can:

* add products
* edit product information
* delete products
* view all products

All data is saved in `products.txt`.

---

## Cart System

Customer can:

* add products with quantity
* remove products
* calculate total price
* clear cart after checkout

---

## Checkout System

During checkout:

* order is created
* stock is updated
* order is saved
* cart is cleared

---

# UML Relationships

| Relationship     | Type        |
| ---------------- | ----------- |
| Admin → User     | Inheritance |
| Customer → User  | Inheritance |
| Customer → Cart  | Composition |
| Cart → Product   | Association |
| Customer → Order | One-to-Many |

---

# Error Handling

The system handles:

* invalid menu input
* invalid quantities
* negative stock
* negative prices
* missing files
* incorrect login

---

# Future Improvements

Possible future upgrades:

* Product search system
* Better order formatting
* GUI interface
* Real database integration
* Payment system
* Password encryption
* Product categories filtering

---

# How to Run

1. Open project in Visual Studio
2. Build solution
3. Run the program
4. Login using credentials from `users.txt`

---

# Sample Login

## Admin

```txt
Username: admin
Password: 5678
```

## Customer

```txt
Username: ali
Password: 1234
```

---

# Author

Developed as a C++ OOP academic project.

```
```
