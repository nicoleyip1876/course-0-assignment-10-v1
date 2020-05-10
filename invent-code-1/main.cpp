#include <iostream>

// ------------------- DO NOT CHANGE THIS IN THIS SECTION -------------------
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------

/* Category Types:
 * 1: Shopping
 * 2: Transportation
 * 3: Other
 */

struct Purchase {
    unsigned int category;    // A category as described above.
    int amount;               // The cost of the purchase.
};

struct Budget {
    unsigned int category;    // A category as described above.
    int limit;                // The maximum amount available for the specified category.
};

/* Prints out a budget in a human readable foramt.
 * Args: 
 *   budget: A Budget Type to Print.
 */
void Print(Budget budget) {
    if (budget.category == 1) {
        std::cout << "Shopping: ";
    } else if (budget.category == 2) {
        std::cout << "Transportation: ";
    } else if (budget.category == 3) {
        std::cout << "Other: ";
    } else {
        std::cout << "Error Invalid Category! ";
    }
    std::cout << '$' << budget.limit;
}
// -----------------------------------------------------------------------
// -----------------------------------------------------------------------
// -----------------------------------------------------------------------

/* Get total cost for the specified category
 * Args:
 *  category: the category for which the total is desired
 *  item_0: A purchase, can be any category
 *  item_1: A purchase, can be any category
 *  item_2: A purchase, can be any category
 * Returns:
 *   total cost of all purchases in the specified category.
 */
int GetTotalForCategory(unsigned int category, Purchase item_0, Purchase item_1, Purchase item_2) {  

 
  /* unsigned int A = 1;
   * unsigned int B = 1;
   * int C = ??;
   * unsigned int D = 1;
   * int E = ??;
   * unsigned int F = 1;
   * int G = ??;
   * Someone sets A - G using some code you can't see.
   * int total = GetTotalForCategory(
   *              category = A, 
   *              item_0 = {category: B, amount: C}, 
   *              item_1 = {category: D, amount: E}, 
   *              item_2 = {category: F, amount: G});
   *
   * A = 1, B = 1, D = 1, F = 1      : total = C + E + G
   * A = 2, B = 1, D = 1, F = 1      : total = 0
   * A = 2, B = 1, D = 2, F = 1      : total = E
   * A = 2, B = 1, D = 2, F = 2      : total = E + G
   * A = 100, B = 100, D = 20, F = 21: total = C
   */
   
  /* create total = 0
   * Check if A matches B:
   *      Add C to total
   * Check if A matches D:
   *      Add E to total
   * Check if F matches A:
   *      Add G to total
   * return total
   */

   // Write code
   int total = 0;
   if (category == item_0.category) {
     total += item_0.amount;
   }
   if (category == item_1.category) {
     total += item_1.amount;
   }
   if (category == item_2.category) {
     total += item_2.amount;
   }
   return total;
}

//how do I incoporate category_num into the function? Yout put 1,2,3 respectively in the arguments which I labeled as category_num
Budget GetBudgetFromUser(int category_num) {
    Budget budget;
     budget.category = category_num;
    std::cin >> budget.limit;
    return budget;
}

Purchase GetPurchaseFromUser() {
    Purchase item;
    std::cout << "Enter a category: 1, 2, 3" << std::endl;
    std::cin >> item.category;
    std::cout << "Enter a amount" << std::endl;
    std::cin >> item.amount;
    return item;
}

void Print(Purchase item) {
  std::cout << "Item category is: " << item.category << std::endl;
  std::cout << "Item amount is: " << item.amount << std::endl;
}


// ------------------- DO NOT CHANGE CODE IN THIS SECTION -------------------
// ----------------------- Updating comments is ok. -------------------------
// --------------------------------------------------------------------------

/* The comment for this function is removed, try to understand what this 
 * function does by reading it. Once you understand, you are welcome to update 
 * this comment to help you remember.
 */
void BudgetStatus(Budget budget, int total_spent) {
    std::cout << "Budget ";
    Print(budget);
    std::cout << " You spent $" << total_spent;
    if (total_spent < budget.limit) {
        std::cout << " and you remained within your budget!";
    } else {
        std::cout << " and you blew the budget!";
    }
    std::cout << std::endl;
}

/* The comment for this function is removed, try to understand what this 
 * function does by reading it. Once you understand, you are welcome to update 
 * this comment to help you remember. Feel free to add comments before lines in
 * the code below as well.
 */
int main() {
    std::cout << "Enter a limit for shopping category" << std::endl;
    Budget limit_shopping = GetBudgetFromUser(1);
    Print(limit_shopping);
    std::cout << std::endl;

    std::cout << "Enter a limit for transportation category" << std::endl;
    Budget limit_transportation = GetBudgetFromUser(2);
    Print(limit_transportation);
    std::cout << std::endl;

    std::cout << "Enter a limit for other category" << std::endl;
    Budget limit_other = GetBudgetFromUser(3);
    Print(limit_other);
    std::cout << std::endl;

    Purchase item0 = GetPurchaseFromUser();
    Print(item0);
    
    Purchase item1 = GetPurchaseFromUser();
    Print(item1);
    
    Purchase item2 = GetPurchaseFromUser();
    Print(item2);

    int total_other = GetTotalForCategory(limit_other.category, item0, item1, item2);
    int total_shopping = GetTotalForCategory(limit_shopping.category, item0, item1, item2);
    int total_transportation = GetTotalForCategory(limit_transportation.category, item0, item1, item2);

    BudgetStatus(limit_other, total_other);
    BudgetStatus(limit_shopping, total_shopping);
    BudgetStatus(limit_transportation, total_transportation);
}
// -----------------------------------------------------------------------
// -----------------------------------------------------------------------
// -----------------------------------------------------------------------