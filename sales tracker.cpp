
#include <iostream> 
#include <iomanip> 
 
using namespace std; 
 
int main() { 
    // Welcome message 
 
    cout << "*****" << endl; 
    cout << "                                             " << endl; 
    cout << "     Welcome to Sales Tracker System         " << endl; 
    cout << "                                             " << endl; 
    cout << "*****" << endl; 
 
    // Ask the user for inputs 
    string phoneNumber[4] = {}; 
    for (int i = 0; i < 4; ++i) 
    { 
        cout << "Enter Phone number for person " << i + 1 << " : "; 
        cin >> phoneNumber[i]; 
    } 
 
    string productId[5] = {}; 
    cout << "Enter product id below..." << endl; 
    for (int i = 0; i < 5; ++i) 
    { 
        loop: 
        cout << "product "<< i + 1 << " : "; 
        cin >> productId[i]; 
        for (int j = 0; j < 5; j++) 
        { 
            if (i != j && productId[i] == productId[j]) 
            { 
                cout << "ID exists" << endl; 
                goto loop; 
            } 
        } 
    } 
 
    // Ask the user for the day length 
    int n; 
    cout << "Input the number of days(1-30): "; 
    cin >> n; 
 
    // Handling exceptions 
    if (n < 1 || n > 30) 
    { 
        cout << "Invalid input!! Please, run again!" << endl; 
        return 1; 
    } 
 
    // Initializing arrays and variables 
    long double sales[n][4][5] = {}; // array data with n days, 4 salesperson and 5 products 
    long 
    double total_sales[5] = {}, total_person[4] = {}, total = 0, monthly[4][5] = {}; 
 
    // Accept sales data 
    for (int k = 0; k < n; k++) 
    { 
        for (int i = 0; i < 4; i++) 
        { 
            for (int j = 0; j < 5; j++) 
            { 
                cout << "Enter the total value for product " << j + 1 << " sold by salesperson " << i + 1 << " on day " << k + 1 << ": "; 
                cin >> sales[k][i][j]; 
            } 
        } 
    } 
    cout << "\n\n"; 
 
    // Monthly summary 
    for (int i = 0; i < 4; i++) 
    { 
        for (int j = 0; j < 5; j++) 
        { 
            for (int k = 0; k < n; k++) 
            { 
                monthly[i][j] += sales[k][i][j]; 
            } 
        } 
    } 
 
    // Calculate total sales per person 
    int total_sales_per_person[4] = {0}; 
    int total_sales_per_product[5] = {0}; 
    for (int i = 0; i < 4; i++) 
    { 
        for (int j = 0; j < 5; j++) 
            total_sales_per_person[i] += monthly[i][j]; 
    } 
 
    // Calculate total sales per product 
    for (int j = 0; j < 5; j++) 
    { 
        for (int i = 0; i < 4; i++) 
            total_sales_per_product[j] += monthly[i][j]; 
    } 
 
    // Loop to calculate the total of 'total sales' array 
    for (int i = 0; i < 5; i++) { 
        total += total_sales_per_product[i]; 
    } 
 
    //  Calculate the bonus 
    double bonus[4] = {}; 
    const double bonusRate = 0.05; 
    for (int i = 0; i < 4; ++i) { 
        bonus[i] = total_sales_per_person[i]*bonusRate; 
    } 
 
    // Display the results 
    cout << " Table" << setw(13); 
    for (int i = 0; i < 4; i++) 
        cout << "Person " << i + 1 << setw(10); 
    cout << "\tTotal_product" << endl; 
 
    for (int i = 0; i < 5; i++) 
    { 
        cout << "Product " << i + 1 << setw(10); 
        for (int j = 0; j < 4; j++) 
            cout << monthly[j][i] << setw(10); 
        cout << "\t" << total_sales_per_product[i] << endl; 
    } 
 
    cout << "Total_person" << setw(7); 
    for (int i = 0; i < 4; i++) 
        cout << total_sales_per_person[i] << setw(10); 
    cout << "\t" << total << endl; 
 
    cout << "Bonus" << setw(14); 
    for (int i = 0; i < 4; i++) 
        cout << bonus[i] << setw(10); 
    cout << "\n\n\n"; 
 
//    Searching particular Product or SalesPerson 
cout << "Do you want a slip summary?" << endl

<< "1. Yes." << endl << "2. No." << endl << "Answer:"; 
    int answer; 
    cin >> answer; 
 
    switch (answer) { 
        case 1: 
        { 
            int num; 
            cout << "what do you want to search for: " << endl << "1. Product record" << endl << "2. Person record" << endl << "Answer: "; 
            cin >> num; 
            if (num == 1) 
            { 
                bool found = false; 
                int n; 
                cout << "Enter the product number: "; 
                cin >> n; 
                cout << "\n\n"; 
                for (int i = 0; i < 5; i++) 
                { 
                    if (n == i + 1) 
                    { 
                        cout << "Product ID: " << productId[i] << endl; 
                        for (int j = 0; j < 4; j++) 
                            cout << "The monthly sales of Product " << i + 1 << " by person " << j + 1 << ": " << monthly[j][i] << endl; 
 
                        cout << "The total sales of product " << i + 1 << " is: " << total_sales_per_product[i] << endl; 
                        found = true; 
                    } 
                } 
                if (!found) 
                    cout << "Sorry!! The Product is not found." << endl; 
                else 
                    cout << "Thanks for using our app" << endl; 
            } 
            else if (num == 2) 
            { 
                bool found = false; 
                int n; 
                cout << "Enter the person's number: "; 
                cin >> n; 
                cout << "\n\n"; 
                for (int i = 0; i < 4; i++) 
                { 
                    if (n == i + 1) 
                    { 
                        // The user's Phone 
                        cout << "Phone number: " << phoneNumber[i] << endl; 
                        for (int j = 0; j < 5; j++) 
                            cout << "The monthly sales of Product " << j + 1 << " by person " << i + 1 << ": " << monthly[i][j] << endl; 
 
                        cout << "The total sales of person " << i + 1 << " is: " << total_sales_per_person[i] << endl; 
                        found = true; 
                    } 
                } 
                if (!found) 
                    cout << "Sorry!! The Person is not found." << endl; 
                else 
                    cout << "Thanks for using our app." << endl; 
            } 
            else 
                cout << "Invalid input!! Please, run again!" << endl; 
            break; 
        } 
        case 2: 
        { 
            cout << "Thanks."  << endl; 
            break; 
        } 
        default: 
            cout << "Invalid input!! Please, run again!" << endl; 
    } 
    return 0; 
}
