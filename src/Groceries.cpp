// Insight Fellows Coding Challenge
// Dataset - InstaCart Grocery Orders
// Friday, March 29, 2019 ~5:54 p.m. to April 9, 2019 ~3:22 a.m.


// Headers
#include <algorithm>
#include <cstdlib>
#include <ctype.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <map>
#include <math.h>
#include <memory>
#include <string>
#include <string.h>
#include <typeinfo>
#include <vector>

using namespace std;

// Classes, Functions, Objects


/*
department_id			vector or set; yet, vector given the need to configure with the unique function
product_id				vector; however, combine with product_details
product_details			map
department_totals		struct or map
*/

typedef struct Totals {
int 				id, orders, inaugural_orders;
};


typedef struct For_Personal_Test {
int					integer, decimal, tenths;
};


class Groceries {

public:
vector<int> 		department_id;
map<string,int>	    product_details;
Totals				*department_totals;
int                 k, products_file_rows, orders_file_rows;

int Counting_Rows(string&, string&);
void Reading_Data(string&, string&, vector<string>&);
void Configure_Data();
void Assign_Department_Data();
void Matching_Data(string&, string&, vector<string>&);
void Export(string&, string&);
void Export_Personal_Tests(string&, string&, string&, int&);

private:
ifstream 			File;
ofstream 			New_File;
int 				i, j, department_data, match, middle, position, department_id_column, product_id_column, reordered_column = 0;;
char 				field = '\0';
string				header_data, header_name, data, product_data;
vector<string>		header;
For_Personal_Test	verify;

int  Search_Id(int&, int, int);
};



int main (int argc, char* argv[] ) {


// Declarations for Reading the Data Files
string 				data_folder = "/Users/TGilchrist/Desktop/Employment/Spring 2019/Insight Fellows/Groceries/input_instacart_2017_05_01/";
string              output_folder = "/Users/TGilchrist/Desktop/Employment/Spring 2019/Insight Fellows/Groceries/output/";
string              test_data_folder = "/Users/TGilchrist/Desktop/Employment/Spring 2019/Insight Fellows/Groceries/test_1/input/";
string              test_output_folder = "/Users/TGilchrist/Desktop/Employment/Spring 2019/Insight Fellows/Groceries/test_1/output/";
string              personal_test_output_folder = "/Users/TGilchrist/Desktop/Employment/Spring 2019/Insight Fellows/Groceries/personal_test/output/";
string              directory_folder;

string 				products_file_name;
string 				orders_file_name;
string 				test_orders_file_name;

vector<string> 		products_header_name;
products_header_name.push_back("product_id");
products_header_name.push_back("department_id");

vector<string> 		orders_header_name;
orders_header_name.push_back("product_id");
orders_header_name.push_back("reordered");

int v=0;
while (argv[v] != NULL) {
    if (argv[v] != "products.csv")  {  products_file_name = "products.csv";
                                       orders_file_name = "order_products__prior.csv";
                                       test_orders_file_name = "order_products.csv";
                                       directory_folder = data_folder;
                                       v++;
                                    }
    else                            { products_file_name = argv[v]; v++;
                                      orders_file_name = argv[v]; v++;
                                    }
    if (argv[2] == "test")          {
            if (argv[3] == NULL)    { directory_folder = "test_folder"; }
            else                    { directory_folder = argv[3];
                                      output_folder = argv[4];          }
                                    }
}

// Declaring Data Object
Groceries 			testGroceriesCY17;

int w = 20024;

// Preparing Output File Name

time_t           	date;  time (&date);

int                 c = 0; int e = 0;
char                Date_Today[11]; Date_Today[11] = '\0'; Date_Today[12] = '\0';
string              Date_Now;

for (int d = 0; d < 11; d++) {
if (d >= 7) { e = 13; Date_Today[d] = ctime(&date)[d+e]; continue;}
else {e = 4; Date_Today[d] = ctime(&date)[d+e]; continue;} }

Date_Now = Date_Today;

string			    output_file_name = "report - " + Date_Now + ".csv";
string				personal_with_map_of_product_details = "report_for_selected_products_with_department - " + Date_Now + ".csv";
string				personal_verify = "report_for_verifying_orders_by_department - " + Date_Now + ".csv";




if (argv[1] == NULL) {

// Test:    Initiating the Process
cout << "Conducting Initial Test Suggesed by Insight" << '\n' << '\n';

// Counting Rows
testGroceriesCY17.products_file_rows = testGroceriesCY17.Counting_Rows(test_data_folder, products_file_name);
testGroceriesCY17.orders_file_rows = testGroceriesCY17.Counting_Rows(test_data_folder, test_orders_file_name);


// Beginning the Process
testGroceriesCY17.Reading_Data(test_data_folder, products_file_name, products_header_name);


// Configuring Data
testGroceriesCY17.Configure_Data();

// Assigning Data
testGroceriesCY17.Assign_Department_Data();

// Matching Data
testGroceriesCY17.Matching_Data(test_data_folder, test_orders_file_name, orders_header_name);

// Creating Output File
testGroceriesCY17.Export(test_output_folder, output_file_name);

delete [] testGroceriesCY17.department_totals;

cout << '\n' << '\n' << "Freed memory" << '\n' << '\n' << '\n';
}




// Initiating the Process

// Declaring Data Object
Groceries 			GroceriesCY17;


// Counting Rows
cout << "A. ";
GroceriesCY17.products_file_rows = GroceriesCY17.Counting_Rows(data_folder, products_file_name);
cout << "   ";
GroceriesCY17.orders_file_rows = GroceriesCY17.Counting_Rows(data_folder, orders_file_name);


// Beginning the Process
GroceriesCY17.Reading_Data(data_folder, products_file_name, products_header_name);


// Configuring Data
GroceriesCY17.Configure_Data();

// Assigning Data
GroceriesCY17.Assign_Department_Data();

// Matching Data
GroceriesCY17.Matching_Data(data_folder, orders_file_name, orders_header_name);

// Creating Output File
GroceriesCY17.Export(output_folder, output_file_name);
GroceriesCY17.Export_Personal_Tests(personal_test_output_folder, personal_with_map_of_product_details, personal_verify, w);

delete [] GroceriesCY17.department_totals;
cout << '\n' << '\n' << "Freed memory";
}



// Functions


int Groceries :: Counting_Rows (string& folder_name, string& file_name) {

string crew;
j=0;
File.open(folder_name + file_name);
while (File >> crew) { if (File.peek()== '\n') {j++;} }
File.close();
cout << "Counting Rows\n" << '\n';
cout << '\t' << "Counted rows for " << file_name << ". There are " << j << " total rows.\n" << '\n';
cout << '\t' << "Accounting for the header row, the number of respective rows is " << (j-1) << ".\n" << '\n';
return (j-1);
}


void Groceries :: Reading_Data (string& folder_name, string& file_name, vector<string>& header_name) {

department_id.reserve( products_file_rows );
product_details.get_allocator().allocate( products_file_rows );

department_data=0;

cout << '\n'<< "B. Reading Data" << '\n' << '\n';
char 			DELIMITER = static_cast<char>(',');

File.open(folder_name + file_name);
cout << '\t' << "File open" << '\n';


while ( File.peek() != '\n' ) {

	field = static_cast<char>(File.get());

	if 			( field == DELIMITER )	        { header.push_back(header_data); header_data.clear(); }
	else if	   	( iscntrl(File.peek()) )		{ header_data += string(1,field); header.push_back(header_data); header_data.clear(); }
	else										{ header_data += string(1,field); i++; }
}

cout << '\n' << '\n' << '\t' << "header[0]\t" << header[0] << '\t' << "header[3]\t" << header[3] << '\n' << '\n';

    i=0;
	while ( i < header.size() )	{
		if ( header[i].compare(header_name.at(0)) == 0 )		{ product_id_column = i; }
		i++;
								}
    i=0;
	while ( i < header.size() ) {
		if ( header[i].compare(header_name[1]) == 0 )			{ department_id_column = i; }
		i++;
								}

cout << '\t';
cout << "product_id_column\t" << product_id_column << '\t' << "department_id_column\t" << department_id_column << '\n' << '\n';


	position = 0;
	while ( !File.eof() ) {

		field = static_cast<char>(File.get());

		if 			( field == DELIMITER )					{ position++; }
		if  	   	( field == '\n' )						{ position = 0; }
        if          ( File.peek() == char_traits<char>::eof() )   { break; }

		if		    (position == product_id_column)
		{ 	while 	( position < (product_id_column+1) )
				{ field = static_cast<char>(File.get());

					if 	(field==DELIMITER) 					{ position++; product_details.emplace(product_data,0); }
                    else if ( isdigit(field) ) 				{ product_data += string(1,field); }
                    //To account for clerical error, whereby misentry still represents an order
                    else if ( isalpha(field) )              { product_data = {"999999"}; position++; }
                    else if ( isspace(field) || isblank(field) )     { product_data = {"999998"}; position++; }
				}
		}



		if		    (position == department_id_column)
		{ 	while	( position < (department_id_column+1) )
				{ field = static_cast<char>(File.get());



					if	(field==DELIMITER) 					{ position++; department_data = atoi(data.c_str());
                                                              department_id.push_back(department_data);
                                                              product_details[product_data]=department_data;
															  data.clear(); department_data=0; product_data.clear(); }
 					if ( field == '\n' )                    { File.putback(field); position++; department_data = atoi(data.c_str());
                                                              department_id.push_back(department_data);
                                                              product_details[product_data]=department_data;
															  data.clear(); department_data=0; product_data.clear(); }
                    else if ( isdigit(field) )              { data += string(1,field); }
                    else if ( isalpha(field) )              { position++; }
                    else if ( isspace(field) || isblank(field) )  { position++; }
				}
		}

						   }



cout << '\n' << '\t' << "Finished reading the data file.\n" << '\n';

File.close();

}




void Groceries :: Configure_Data () {

cout << '\n' << "C. Configuring Data and Addressing Duplicates" << '\n' << '\n';

cout << '\t' << "Before\n";
cout << '\t' << "department_id.size()\t" << department_id.size() << '\n';
cout << '\t' << "department_id[0]\t" << department_id[0] << '\n';
cout << '\t' << "department_id.end()\t" << department_id.at(2) << '\n' << '\n';


vector<int>::iterator iterate;

iterate=unique( department_id.begin(), department_id.end() );

sort( department_id.begin(), department_id.end() );
iterate=unique( department_id.begin(), department_id.end() );
department_id.resize( std::distance( department_id.begin(), iterate ) );

cout << '\t' << "After\n";
cout << '\t' << "department_id.size()\t" << department_id.size() << '\n';
cout << '\t' << "department_id[0]\t" << department_id[0] << '\n';
cout << '\t' << "department_id.end()\t" << department_id.at(2) << '\n' << '\n';

}


void Groceries :: Assign_Department_Data() {

cout << '\n' << "D. Assign Data" << '\n' << '\n';

department_totals = new Totals[department_id.size()];

j=0;
while ( j < department_id.size() ) { department_totals[j].id = department_id.at(j);
                                     department_totals[j].orders = 0;
                                     department_totals[j].inaugural_orders = 0;
j++; }
j=0;
}


void Groceries :: Matching_Data (string& folder_name, string& file_name, vector<string>& header_name) {

/*
This function:
1. Reads the header names of each column
2. Discerns which columns have the product_id and reorder data
3. Matches the product_id data
4. Filters the data by discerning any delimiter, end of line, or end of file characters
5. Obtains the product_id data and uses a search function to find the corresponding entry position in a department_id vector container
6. Counts the number of totl orders and first-time orders
*/

cout << '\n' << "E. Matching Data" << '\n' << '\n' << '\n';


char 			DELIMITER = static_cast<char>(',');

header.clear();

verify.decimal = 0;
verify.tenths = 0;
verify.integer = 0;

File.open(folder_name + file_name);


// 1. Identifying the Header Column Names and Inserting Them into a Vector Container
while ( File.peek() != '\n' ) {

	field = static_cast<char>(File.get());

	if 			( field == DELIMITER )		    			{ header.push_back(header_data); header_data.clear(); }
	else if	   	( File.peek() == '\n' )					    { header_data += string(1,field); header.push_back(header_data); header_data.clear(); }
	else													{ header_data += string(1,field); }
							  }

cout << '\t' << "These are the names of the headers to each column.\n" << '\n' << '\t';
i=0;
while(i<header.size()) { cout<< header[i++] << '\t'; }
cout << '\n';



// 2. Discerning Which Columns Have the Data for Product_Id and Reorders
    i=0;
	while ( i < header.size() )	{
		if ( header[i].compare(header_name.at(0)) == 0 )		{ product_id_column = i; }
		i++;
								}
    i=0;
	while ( i < header.size() ) {
		if ( header[i].compare(header_name.at(1)) == 0 )			{ reordered_column = i; }
		i++;
								}

cout << '\n';
cout << '\t' << "product_id_column\t" << product_id_column << '\n' << '\n';
cout << '\t' << "reordered_column\t" << reordered_column << '\n' << '\n';



// 3. Matching the Product_Id

	position=0; field = '\0';
	while ( !File.eof() ) {

	field = static_cast<char>(File.get());

	// 4. Discerning if the Input is a Delimiter, End of Line Character, or the End of the File
	if        	( field == DELIMITER )  		 	{  position++;  }
	if         	( field == '\n' )       		    {  position = 0; }

    if          ( File.peek() == char_traits<char>::eof() )   { break; }




	// 5. Obtaining the Product Data from the Product_Id Column and Using a Search to Match with the Entry Position of the Depatment_Id Vector Container
	if        	(position == product_id_column) {

		 while 	( position < (product_id_column+1) )
				{ field = static_cast<char>(File.get());
					if 	(field==DELIMITER) 					{ position++;
															  department_data = product_details[product_data];
															  match = Search_Id( department_data, 0, department_id.size() );
															  department_data=0; product_data.clear();
                                                            }
					else if ( isdigit(field) )			    { product_data += string(1,field); }
                    else if ( isalpha(field) )              { position++; }
                    else if ( isspace(field) || isblank(field) )  { position++; }
				}

                                                }

    // 6. Counting the Number of Total Orders and First-Time Orders
	if 		(position == reordered_column) {          department_totals[match].orders++;
                    position++;
					field = static_cast<char>(File.get());

					if  (field == '0')          	        { department_totals[match].inaugural_orders++; verify.integer++; }

                            /*if ( ispunct(File.peek()) )     { field = static_cast<char>(File.get()); verify.decimal++;
                                if ( File.peek() >= 0)      { field = static_cast<char>(File.get());
                                    if (field != '0')       { department_totals[match].inaugural_orders--; verify.integer--; }
                                    else                    { verify.tenths++; }
															}
															}
							else {continue; }				}*/

                    if  ( field == '\n' )                       { position=0; }

                    else { position++; }
                                            }

                      }
File.close();
}


int Groceries :: Search_Id (int& data_id, int id_vector_begin, int id_vector_end) {

middle = 0;

	for (int in_here_begin = id_vector_begin; in_here_begin <= id_vector_end;) {

		middle = std::div((in_here_begin + id_vector_end),2).quot;

		if ( data_id < department_id.at(middle) )			{ id_vector_end = middle--; }

		else if ( data_id > department_id.at(middle) )		{ in_here_begin = middle++; }

		else if ( data_id == department_id.at(middle) )		{ return middle; }

		else if ( in_here_begin == id_vector_end )			{ return -1; }

	}

}


void Groceries :: Export (string& folder_name, string& file_name) {

int total_orders, inaugural_orders = 0;

k=0;
while (k<department_id.size()) {total_orders += department_totals[k].orders; k++;}

k=0;
while (k<department_id.size()) {inaugural_orders += department_totals[k].inaugural_orders; k++;}
k=0;


cout << '\t' << '\n';
cout << '\t' << "The total number of orders is " << total_orders << ".\n" << '\n';
cout << '\t' << "The total number of first-time orders is " << inaugural_orders << ".\n" << '\n';
cout << '\t' << "The overall percentage of first-time orders to total orders is ";
cout.precision(2);
cout << fixed << static_cast<float>(inaugural_orders) / static_cast<float>(total_orders) << ".\n" << '\n' << '\n';


New_File.open(folder_name + file_name);
New_File.setf(ios::fixed); cout.setf(ios::fixed);

New_File << "department_id" << ",";
New_File << "number_of_orders" << ",";
New_File << "number_of_first_orders" << ",";
New_File << "percentage";


i=0;
do {

    if (department_totals[i].orders > 0) {

        New_File.precision(0);
        New_File << '\n';
        New_File << department_totals[i].id << ",";
        New_File << department_totals[i].orders << ",";
        New_File << department_totals[i].inaugural_orders << ",";
        New_File.precision(2);
        New_File << static_cast<float>(department_totals[i].inaugural_orders) / static_cast<float>(department_totals[i].orders) ;
                                         }
i++;
	     }  while ( i < department_id.size() );

New_File.close();

}


void Groceries :: Export_Personal_Tests (string& folder_name, string& a_file, string& another_file, int& w) {

if (w > 1) {

cout.setf(ios::fixed); cout.precision(0);

cout << "F. My Personal Test\n";

cout << '\n' << '\n';
cout << '\t' << "product_id" << '\t';
cout << "department_id" << '\t';

cout.precision(0);
cout << '\n';
k=w;
while (w < (k+20)) {
cout << '\n' << '\t';
cout << w << '\t' << '\t';
cout << product_details[ to_string(w) ] << '\t';
w++;
}w=k;


cout << '\n' << '\n';
cout << '\t' << "department_totals[0].id" << '\t' << ".inaugural_orders" << '\t' << ".orders" << '\n';
cout << '\t' << department_totals[0].id << '\t' << department_totals[0].inaugural_orders << '\t' << department_totals[0].orders << '\n' << '\n';
cout << '\t' << "department_totals[1].id" << '\t' << ".inaugural_orders" << '\t' << ".orders" << '\n';
cout << '\t' << department_totals[1].id << '\t' << department_totals[1].inaugural_orders << '\t' << department_totals[1].orders << '\n' << '\n';
cout << '\t' << "department_totals[128].id" << '\t' << ".inaugural_orders" << '\t' << ".orders" << '\n';
cout << '\t' << department_totals[128].id << '\t' << department_totals[128].inaugural_orders << '\t' << department_totals[128].orders << '\n' << '\n';
cout << '\t' << "department_totals[129].id" << '\t' << ".inaugural_orders" << '\t' << ".orders" << '\n';
cout << '\t' << department_totals[129].id << '\t' << department_totals[129].inaugural_orders << '\t' << department_totals[129].orders;

}


New_File.open(folder_name + a_file);
New_File.setf(ios::fixed);
New_File.precision(0);

New_File << "product_id" << ",";
New_File << "department_id" << ",";

k=w;
while (w < k+20) {
New_File << '\n';
New_File << w << ",";
New_File << product_details[ to_string(w) ] << ",";
w++;
}w=0;

New_File.close();


New_File.open(folder_name + another_file);
New_File.setf(ios::fixed);
New_File.precision(0);

New_File << "department_totals[0].id" << "," << ".inaugural_orders" << "," << ".orders" << '\n';
New_File << department_totals[0].id << "," << department_totals[0].inaugural_orders << "," << department_totals[0].orders << '\n' << '\n';
New_File << "department_totals[1].id" << "," << ".inaugural_orders" << "," << ".orders" << '\n';
New_File << department_totals[1].id << "," << department_totals[1].inaugural_orders << "," << department_totals[1].orders << '\n' << '\n';
New_File << "department_totals[128].id" << "," << ".inaugural_orders" << "," << ".orders" << '\n';
New_File << department_totals[128].id << "," << department_totals[128].inaugural_orders << "," << department_totals[128].orders << '\n' << '\n';
New_File << "department_totals[129].id" << "," << ".inaugural_orders" << "," << ".orders" << '\n';
New_File << department_totals[department_id.size()-1].id << "," << department_totals[department_id.size()-1].inaugural_orders << "," << department_totals[department_id.size()-1].orders;


New_File.close();

}
