#include <iostream>

using namespace std;

int main()
{
	int rows, columns;
	
	cout << "Rows: ";
	cin >> rows;
	
	cout << "Columns: ";
	cin >> columns;
	
	int** arr = new int*[rows];
	
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[columns];
		
		for (int j = 0; j < columns; j++)
		{
			arr[i][j] = 0;
		}
	}
	
	while (true)
	{
		int x, y;
		
		cout << "Enter x and y to fill seats (-1 to exit): " << endl;
		
		cin >> x;
		
		if (x == -1) break;
		
		cin >> y;
		
		if (y == -1) break;
		
		if (x < 0 || x >= rows || y < 0 || y >= columns)
		{
			cout << "Invalid coordinates" << endl;
			continue;
		}
		
		arr[x][y] = 1;
	}
	
	cout << "\nSeats:" << endl;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	for (int i = rows - 1; i >= 0; i--)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
