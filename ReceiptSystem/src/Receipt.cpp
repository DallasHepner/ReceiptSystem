#include "Receipt.h"
#include <iomanip>

/*
 * @brief Add ReceiptItems to a vector in Receipt to store and print
 * @remark Checks to see if ReceiptItem is already in the list.
 *          If true, rather than adding ReceiptItem to vector,
 *          we will add ReceiptItems together using ReceiptItem overloaded addition operator
 * @param ReceiptItem user chosen ReceiptItem to add to list
 */
void Receipt::AddReceiptItem(ReceiptItem receiptItem)
{
    int position = Find(receiptItem);

    if(position != -1)
        receiptItems_.at(position) = receiptItems_.at(position) + receiptItem;
    else
        receiptItems_.push_back(receiptItem);
}


/*
 * @brief prints each ReceiptItem in the list including
 *      Item name
 *      Item Quantity
 *      Item Price
 *      Item Total
 *      then prints a separating line and a final total
 */
void Receipt::PrintReceipt() const
{
    double total = 0;

    // print labels
    std::cout << std::left  << std::setw(50) << "PRODUCT";
    std::cout << std::left  << std::setw(10)  << "QTY";
    std::cout << std::right << std::setw(10)  << "PRICE" << std::endl;

    if(receiptItems_.size() == 0)
    {
        std::cout << "Receipt has no items added" << std::endl;
    }
    for (auto receiptItem : receiptItems_)
    {
        total += receiptItem.GetTotal();

        std::cout << receiptItem << std::endl;
    }

    // print line
    std::cout << std::setw(70) << std::setfill('-') << '-' << std::endl;

    //print total
    std::cout << std::setfill(' ');
    std::cout << std::left << std::setw(59) << "TOTAL ";
    std::cout << std::left << "$";
    std::cout << std::right << std::setw(10) << total << std::endl;
}

/*
 * @brief private helper function that looks for a given ReceiptItem.
 * @remark uses Item class overloaded equality operator
 * @param ReceiptItem to search for
 * @return int - position in vector or -1 if ReceiptItem is not in list
 */
int Receipt::Find(const ReceiptItem receiptItem) const
{
    int position = 0;
    for(auto element : receiptItems_)
    {
        if (element.GetItem() == receiptItem.GetItem())
            break;
        ++position;
    }

    if(position == receiptItems_.size())
        position = -1;

    return position;
}

////The following methods are for testing purposes and are not intended for use in your program

/*
 * @brief Gets the size of the vector that is managing the ReceiptItems
 * @return int size of class vector receiptItems_
 */

int Receipt::GetReceiptItemCount()
{
    return receiptItems_.size();
}


/*
 * @brief Tallies the number of Items specified by each ReceiptItem for a final count
 * @returns int count of Items
 */
int Receipt::GetItemCount()
{
    int count = 0;

    for(auto element : receiptItems_)
    {
        count += element.GetQuantity();
    }
    return count;
}

/*
 * @brief tallies each ReceiptItem for a final price
 * @returns double final price
 */
double Receipt::GetFinalPrice()
{
    double total = 0;

    for(auto element : receiptItems_)
    {
        total += element.GetTotal();
    }
    return total;
}
