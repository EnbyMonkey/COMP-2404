# COMP 2404 - Assignment 3
Emile Greer
100914184

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)

## General info
A simple program to simulate management of products in a store and warehouses.

## Technologies
Project is created with:
* C++
* Makefile
and includes:
* UML class diagram

## Setup
To compile and run this project, Type 'make' or 'make all', then ./a3.

```
../assignment3/$ make
.
.
.
../assignment3/$ ./a3
Launching...
```

## Class Summaries
* View: Output to console, get user input from console.
* Control: Initialize store, store shelves, warehouses, products. Initialize View. Tests program via receiveProduct(),
  fillOrder(), queueTest(), locationTest().
* Store: Responsible for keeping shelves stocked with product, and retrieving products from warehouse locations.
  Can receive new products and fill customer orders.
* WHLocation: Warehouse location. Can hold a single type of product. Store can add or take product to/from WHLocation.
* StoreLocation: Represents the specific shelf/location where a product is displayed in Store. Store can add or take
  product to/from StoreLocation.
* Location: An abstract class, from which WHLocation and StoreLocation are derived classes.
* Product: Represents a product that is sold in the Store. Keeps track of all warehouses which store this product.
* Queue: A FIFO linked list, which is used to take older products from warehouses before newer ones (important since
  some products have expiration dates).
* List: A linked list which stores the names of all products sold at the Store (in alphabetical order).
