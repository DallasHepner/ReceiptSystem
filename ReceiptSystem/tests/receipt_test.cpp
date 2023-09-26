#include "Item.h"
#include "ReceiptItem.h"
//#include "Receipt.h"

#include <array>
#include <iostream>
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
//for floating point numbers
using namespace Catch::Matchers::Floating;

TEST_CASE("Item Class Constructors & Getters")
{
    INFO("Checks that default constructor creates objects with correct default values")
    Item item1;
    CHECK(item1.GetId() == 0);
    CHECK(item1.GetName() == "no name");
    CHECK(item1.GetDescription() == "");
    CHECK(item1.GetPrice() == 0);

    INFO("Checks that general constructor creates objects with correct values")
    Item item2(5, "test product", "test description that is longer than the name of the product", 15.99);
    CHECK(item2.GetId() == 5);
    CHECK(item2.GetName() == "test product");
    CHECK(item2.GetDescription() == "test description that is longer than the name of the product");
    CHECK(item2.GetPrice() == 15.99);

}

TEST_CASE("Item Class Setters & Getters")
{
    // Checks that the setters are setting correct values
    Item testItem;

    // Checking id_ getter & setter
    testItem.SetId(1);
    CHECK(testItem.GetId() == 1);
    testItem.SetId(-1);
    CHECK(testItem.GetId() == 0);

    // Checking name_ getter & setter
    CHECK(testItem.GetName() == "no name");
    testItem.SetName("New Name");
    CHECK(testItem.GetName() == "New Name");

    // Checking description_ getter & setter
    CHECK(testItem.GetDescription() == "");
    testItem.SetDescription("New description");
    CHECK(testItem.GetDescription() == "New description");

    // Checking price_ getter & setter
    CHECK(testItem.GetPrice() == 0);
    testItem.SetPrice(5.50);
    CHECK(testItem.GetPrice() == 5.50);
    testItem.SetPrice(-5.50);
    CHECK(testItem.GetPrice() == 0);
}

TEST_CASE("Item's Overloaded Operators")
{
    // Checks to make sure the overloaded operators are working correctly
    Item item1(5, "test product", "test description that is longer than the name of the product", 15.99);
    Item item2(5, "test product", "test description that is longer than the name of the product", 15.99);
    CHECK(item1 == item2);


    // Checks how the name_ parameter impacts the overloaded equality operator
    item1.SetName("Test Product");
    CHECK_FALSE(item1 == item2);
    item1.SetName("test product");
    CHECK(item1 == item2);

    // Checks how the id_ parameter impacts the overloaded equality operator
    item1.SetId(3);
    CHECK_FALSE(item1 == item2);
    item1.SetId(5);
    CHECK(item1 == item2);

    // Checks how the description_ parameter impacts the overloaded equality operator
    item1.SetDescription("testing a different description");
    CHECK_FALSE(item1 == item2);
    item1.SetDescription("test description that is longer than the name of the product");
    CHECK(item1 == item2);

    // Checks how the price_ parameter impacts the overloaded equality operator
    item1.SetPrice(16.00);
    CHECK_FALSE(item1 == item2);
    item1.SetPrice(15.99);
    CHECK(item1 == item2);
}

TEST_CASE("ReceiptItem Class Constructors")
{
    // Checks that default constructor creates objects with correct default values
    ReceiptItem receiptItem1;
    Item item1;
    CHECK(receiptItem1.GetItem() == item1);
    CHECK(receiptItem1.GetQuantity() == 0);
    CHECK(receiptItem1.GetTotal() == 0);

    // Checks that general constructor creates objects with correct given values
    Item item2(5, "test product", "test description that is longer than the name of the product", 15.99);
    ReceiptItem receiptItem2(item2, 4);
    CHECK(receiptItem2.GetItem() == item2);
    CHECK(receiptItem2.GetQuantity() == 4);
    CHECK(receiptItem2.GetTotal() == 4 * 15.99);
}

TEST_CASE("ReceiptItem Class Setters & Getters")
{
    ReceiptItem receiptItem1;
    Item item1;
    Item item2(5, "test product", "test description that is longer than the name of the product", 15.99);

    // Uses ReceiptItem getters to check that the ReceiptItem object has default values
    CHECK(receiptItem1.GetItem() == item1);
    CHECK(receiptItem1.GetQuantity() == 0);
    CHECK(receiptItem1.GetTotal() == 0);

    // Uses ReceiptItem getters to check that the setters successfully set new values
    receiptItem1.SetItem(item2);
    CHECK(receiptItem1.GetItem() == item2);
    receiptItem1.SetQuantity(15);
    CHECK(receiptItem1.GetQuantity() == 15);
    CHECK(receiptItem1.GetTotal() == 15 * 15.99);
}


TEST_CASE("ReceiptItem operator+ that adds two ReceiptItems together")
{
    // Creating several Item and ReceiptItem objects
    Item item1(5, "test product", "test description that is longer than the name of the product", 15.99);
    Item item2(5, "test product", "test description that is longer than the name of the product", 15.99);
    Item item3(6, "test product 2", "test description that is longer than the name of the product", 10.12);

    ReceiptItem receiptItem1(item1, 1);
    ReceiptItem receiptItem2(item2, 3);
    ReceiptItem receiptItem3(item3, 2);

    // Checks that operator+ correctly adds together two ReceiptItems w/ the same Item.
    // Should not care what quantity is when adding two LogItems together.

    // Same quantities
    ReceiptItem receiptItemResult = receiptItem1 + receiptItem1;
    CHECK(receiptItemResult.GetItem() == item1);
    CHECK(receiptItemResult.GetQuantity() == 2);

    // Different quantities
    receiptItemResult = receiptItem1 + receiptItem2;
    CHECK(receiptItemResult.GetItem() == item1);
    CHECK(receiptItemResult.GetQuantity() == 4);

    // Checks that operator+ returns correct results when the item in the ReceiptItem is different
    CHECK_THROWS(receiptItem1 + receiptItem3);
}

TEST_CASE("ReceiptItem operator+ that adds an integer")
{
    // Creating Item and ReceiptItem objects
    Item item1(5, "test product", "test description that is longer than the name of the product", 15.99);
    ReceiptItem receiptItem1(item1, 1);

    // Checks that operator+ returns correct results when adding an integer value to the right-hand side of an ReceiptItem object
    ReceiptItem receiptItemResult = receiptItem1 + 5;
    CHECK(receiptItemResult.GetItem() == item1);
    CHECK(receiptItemResult.GetQuantity() == 6);

    // Checks that the friend operator+ returns correct results when adding an integer value to the left-hand side of an ReceiptItem object
    receiptItemResult = 5 + receiptItem1;
    CHECK(receiptItemResult.GetItem() == item1);
    CHECK(receiptItemResult.GetQuantity() == 6);
}

//TEST_CASE("Receipt Class Tests")
//{
//    // Create Item objects
//    Item item1(5, "test product", "test description that is longer than the name of the product", 15.99);
//    Item item2(5, "test product", "test description that is longer than the name of the product", 15.99);
//    Item item3(6, "test product 2", "test description that is longer than the name of the product", 10.12);
//
//    // Create ReceiptItem objects using above Item objects
//    ReceiptItem ReceiptItem1(item1, 1);
//    ReceiptItem ReceiptItem2(item2, 3);
//    ReceiptItem ReceiptItem3(item3, 2);
//
//    // Creat Receipt object
//    Receipt testReceipt;
//    CHECK(testReceipt.GetFinalPrice() == 0);
//
//    testReceipt.AddReceiptItem(ReceiptItem1);
//    CHECK(testReceipt.GetFinalPrice() == 15.99);
//    CHECK(testReceipt.GetReceiptItemCount() == 1);
//    CHECK(testReceipt.GetItemCount() == 1);
//
//    testReceipt.AddReceiptItem(ReceiptItem2);
//    CHECK(testReceipt.GetFinalPrice() == 15.99 * 4);
//    CHECK(testReceipt.GetReceiptItemCount() == 1);
//    CHECK(testReceipt.GetItemCount() == 4);
//
//    testReceipt.AddReceiptItem(ReceiptItem3);
//    CHECK(testReceipt.GetFinalPrice() == 15.99 * 4 + 10.12 * 2);
//    CHECK(testReceipt.GetReceiptItemCount() == 2);
//    CHECK(testReceipt.GetItemCount() == 6);
//}





