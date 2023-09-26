# Receipt System

---
In this activity you will be creating classes for a system that handles receipts. 
These classes will not be designed for a specific business in mind. Instead, they will be a generic and applicable to most business needs.
Once the classes are complete you will use them in main to create objects for a business of your choice.
---
## Objectives
Demonstrate knowledge about the following topics:

- Writing classes
- Using objects
- Passing & Returning objects in functions
- Overloading operators for user defined data types
- Simple try/catch blocks

### Files to work on
The following files are included in the src folder for you to either work on or use.

- `src/Item.h`
- `src/Item.cpp`
- `src/ReceiptItem.h`
- `src/ReceiptItem.cpp`
- `src/Receipt.h`    do not modify
- `src/Receipt.cpp`  do not modify
- Your driver file will be `src/main.cpp`

### Unit Tests
**Do NOT modify the unit tests!** Your code will be tested against a separate copy than what you have.

- `tests/receipt_test.cpp`

### The Problem to Solve

You and a team of software engineers have been tasked to create a receipt system. 

You have been assigned by your team to create two out of three classes that will be used: `Item` and `ReceiptItem`

The Item class will store information about any product that the user is purchasing. 
The purpose of the ReceiptItem class will be to manage the quantity of each Item.

To start, the program will need to store products as Item objects. Write code to create a class called Item.

---
# Part I - Writing Classes

## The Item Class

Files for modification
- `Item.h`
- `Item.cpp`

### Member Variables

The `Item` class will have four private member variables:

- `int id_` - an integer value that uniquely identifies the object
- `string name_` - the name of the item
- `string description_` - a brief description of the item
- `double price_` - the price of the item

### Member Functions

The Item class will need several functions, include constructors, getters, setters, and some overloaded operators.

#### Constructors

This class will need two constructors. 

- Default 
    - Written inline using an initializer list
    - No parameters
    - sets id_ to 0
    - sets price_ value to zero
    - sets name_ value to "no name"
    - sets description_ value to empty string

- General 
    - Parameters should include (in this order): int id, string name, string description, double price 
    - Definition should set the member variable to user chosen values. Should not allow user to set member variable values to a negative number. If the user tries this, give the variable a default value of 0.

#### Getters

Create getter functions that return the member variable value when called. 

These can be defined inline or in the source file (Item.cpp).

- Return Types - These should each be set to have the return type that is the same as the attribute being returned. For example, this means that for id_, the return type should be int. 
- Names - Should use the word 'Get' then the name of the attribute. For example, for id_ we should see `GetId`. Make sure to use UpperCammelCase.
- Parameters - No parameters
- Read-Only - Make these functions const since we will not be modifying the member variables within any of the function definitions.
- Definition - These should simply return the member variable values.

#### Setters

Create setters that allow the class to control what the user can set the variables to.

These must be defined in the source file (Item.cpp)

- Return Types: These should not return any values so make them have a return type of `void`
- Names - Should use the word 'Set' then the name of the attribute. For example, for id_ we should see `SetId`. Make sure to use UpperCammelCase.
- Parameters - Each setter should accept one parameter. It should be the same type as the related attribute. For example, `id_` is an int, so we will want to set the parameter data type as an int.
- Definition - These should set the values of each member variable to whatever is passed in. Keep in mind that if the user passes in a number that is negative, we should give the member variable the default value of 0.

#### Overloaded Operators

The Item class will have 2 overloaded operators

- Overloaded equality operator: `==`
    - Member function
    - This function should compare the member variables for two Item objects. Returns true if they are all equal and false if any are not.
    
- Overloaded inserter operator: `<<` 
    - Friend function
    - Prints the member variables of an Item object. Formatting is not important.

In the first section of main.cpp there are several TODO comments for creating and using Item objects. Follow these directions to use and test your Item class.

## The ReceiptItem Class

This class will manage the quantity of each item

Files for modification
- ReceiptItem.h
- ReceiptItem.cpp

The ReceiptItem class will have 2 private member variables:

- item_ - Instance of the Item class
- quantity_ type integer, keeps track the item count on our receipt

### Constructors

This class will need two constructors.

- Default
    - Written inline using an initializer list
    - No parameters
    - calls Item default constructor
    - sets numerical values to zero

- General
    - Parameters should include (in this order): Item food, int quantity
    - Sets the member variables to user chosen values. Should not allow user to set member variable values to a negative number. If the user tries this, give the variable a default value of 0.

#### Getters

Create getter functions that return the member variable value when called. These should follow the same guidelines as the Item getters.

These can be defined inline (`ReceiptItem.h`) or in the source file (`ReceiptItem.cpp`).

- Return Types - These should each be set to have the return type that is the same as the attribute being returned. 
- Names - Should use the word 'Get' then the name of the attribute. Make sure to use UpperCamelCase.
- Parameters - No parameters
- Read-Only - Make these functions are const since we will not be modifying the member variables within any of the function definitions.
- Definition - These should simply return the member variable values.

#### Getter for a Calculated Value
- `GetTotal()`
  - Gets the total price for the quantity of item's 
  - No parameters
  - Returns the total price for that receipt item
_Example:_ If the ReceiptItem stores an Item that has a price of $2.99 and the `quantity_` of that item in the `ReceiptItem` is 3, then `GetTotal()` would return $8.97.

#### Setters

These must be defined in the source file (ReceiptItem.cpp). These should follow the same guidelines as the Item setters.

- Return Types: These should not return any values so make them type `void`
- Names - Should use the word 'Set' then the name of the attribute. Make sure to use UpperCamelCase.
- Parameters - Each setter should accept one parameter. It should be the same type as the related attribute.
- Definition - These should set the values of each member variable to whatever is passed in. Keep in mind that if the user passes in a number that is negative, we should give the member variable the default value of 0.

#### Overloaded Operators

The ReceiptItem class will have 6 overloaded operators

- Overloaded addition operator: +
    - Adds together two ReceiptItems.
    - Allows the user to add two ReceiptItem objects together that have the same Item and combines the quantities. For example; `myReceiptItem1 + myReceiptItem2`
        To ensure both ReceiptItem objects have the same Item member variable, use a try/catch block. If they are not the same then throw an error.
    - Returns an updated ReceiptItem object

- Overloaded addition operator for integers: +
    - Allows the user to add an integer to a ReceiptItem object as the right-hand operand. For example: `myReceiptItem + 5`
    - Returns an updated ReceiptItem object

- Overloaded subtraction operator for integers: -
    - Allows the user to subtract an integer from a ReceiptItem object as the right-hand operand. For example: `myReceiptItem - 5`
    - Returns an updated ReceiptItem object

 - Overloaded addition operator for integers: +
     - Allows the user to add an integer to an ReceiptItem object as the left-hand operand. For example: `5 + myReceiptItem`
     - should return an updated ReceiptItem object

- Overloaded inserter operator: <<
    - Prints specific member variables of the ReceiptItem object and stored Item object.
    - Item `name_`
      - Left justified with a width of 50 chars
    - ReceiptItem `quantity_`
      - Left justified with a width of 9 chars
      - Should look like this: `(2)` 
        - Hint: Make the `(quantity_)` into a string using the std::to_string() function before trying to format with iomanip to make it work with ()
    - Print `$`
    - Item `price_`
      - Right justified with a width of 10
    - Returns an ostream object

Hint: Remember to #include the <iomanip> library, especially if you are on a Mac. Macs don't typically show a compiler error when it is missing, but Windows do.

In the first section of main.cpp there are several TODO comments for creating and using ReceiptItem objects. Follow these directions to use and test your ReceiptItem class. 

---
# Part II - Trying everything in main.cpp

Now that each of your classes have been created. If you haven't yet already, switch over to main and follow the directions listed throughout the page in //TODO comments and print statements
up until Part 3.

---
# Part III - Generating a Receipt

In this section we will use our newly defined classes to output our ReceiptItems in a formatted receipt with a total.

## Receipt Class
It is common in the real world to work in teams to write programs. When this is the case, the workload can be split up so that one person writes one part of the program while another works on another section.
For this part of the activity, you will use the Receipt class. It has been written by someone else to work with your completed Item and ReceiptItem classes. 

The purpose of the Receipt class is to assist with accepting and printing an itemized receipt and total. 
Now that you have written the classes to create the Item and ReceiptItem objects, 
you will use the Receipt class to use them by storing as ReceiptItems into a vector.
You will then be able to print the list of ReceiptItems along with the final 

### How to use the Receipt Class

1. `#include` the Receipt class file header in main
2. Create a Receipt object. You will only need one instance.
3. Look in the CMakeList.txt file in under the src folder. Remove the comment marks in front of the Receipt.h and Receipt.cpp files and the choose Reload Changes in the blue bar that appears at the top of the file.
4. Use the AddReceiptItem() method several times, adding many of your ReceiptItems to the vector to print.
5. After this is finished, call the PrintReceipt() method. Your output should look similar to the following example:

```bash
   PRODUCT                                           QTY            PRICE
   Tomato                                            (5)      $      6.45
   Lettuce                                           (3)      $      2.97
   Bread                                             (3)      $      6.27
   Deli Turkey                                       (3)      $     11.97
   Mayonnaise                                        (1)      $      1.50
   ----------------------------------------------------------------------
   TOTAL                                                      $     29.16
```

## Submission
Run the unit tests to make sure they are all passing. Take a screenshot of the passing tests.

Verify that main has the correct output. Take a screenshot of the PrintReceipt() output.

Zip up the folder called src. Should include the following files: Item.cpp, Item.h, main.cpp, Receipt.h, Receipt.cpp, ReceiptItem.cpp, and ReceiptItem.h

Submit your work in the Challenge Activity assignment page for Module 3.
