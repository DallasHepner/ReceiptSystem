#ifndef RECEIPT_H
#define RECEIPT_H

#include <vector>
#include <iostream>
#include "ReceiptItem.h"


class Receipt {

private:
    std::vector<ReceiptItem> receiptItems_;
    int Find(const ReceiptItem) const;

public:
    void AddReceiptItem(ReceiptItem receiptItem);
    void PrintReceipt() const;

    //for testing not for use in your code
    int GetReceiptItemCount();
    int GetItemCount();
    double GetFinalPrice();

};


#endif //RECEIPT_H
