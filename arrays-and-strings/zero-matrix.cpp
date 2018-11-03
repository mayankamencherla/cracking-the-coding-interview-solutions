#include <iostream>
#include <vector>

using namespace std;

/**
 * This method nullifies the given row in the matrix
 *
 * @param vector<vector<int>>& matrix
 * @param int j
 * @return void
 */
void nullifyRow(vector<vector<int>>& matrix, int i)
{
    for (int j=0; j<matrix[i].size(); j++)
    {
        matrix[i][j] = 0;
    }
}

/**
 * * This method nullifies the given col in the matrix
 *
 * @param vector<vector<int>>& matrix
 * @param int j
 * @return void
 */
void nullifyCol(vector<vector<int>>& matrix, int j)
{
    for (int i=0; i<matrix.size(); i++)
    {
        matrix[i][j] = 0;
    }
}

/**
 * This method takes in a MxN matrix, and nullifies entire row and column if element is zero
 *
 * Space complexity : This algorithm consumes O(1) additional memory
 * Time complexity  : This algorithm consumes O(m*n) time
 *
 * @param vector<vector<int>> matrix
 * @return vector<vector<int>>
 */
vector<vector<int>> zeroMatrix(vector<vector<int>>& matrix)
{
    int m = matrix.size(); int n = matrix[0].size();

    // We can use the first row and column as indicator of nullifying entire row / column
    // The way we do this :
    // 1. We check if row0 or col0 has to be nullified
    // 2. After that, if we find a 0 anywhere else:
    //    a. matrix[i][0] = 0 indicates that row[i] should be null
    //    b. matrix[0][j] = 0 indicates that col[j] should be null

    bool firstRowNull = false, firstColNull = false;

    for (int j=0; j<n; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowNull = true;

            break;
        }
    }

    for (int i=0; i<m; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColNull = true;

            break;
        }
    }

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;

                matrix[0][j] = 0;
            }
        }
    }

    // O(m)
    for (int i=1; i<m; i++)
    {
        if (matrix[i][0] == 0) nullifyRow(matrix, i);
    }

    // O(n)
    for (int j=1; j<n; j++)
    {
        if (matrix[0][j] == 0) nullifyCol(matrix, j);
    }

    if (firstRowNull) nullifyRow(matrix, 0);

    if (firstColNull) nullifyCol(matrix, 0);

    return matrix;
}

void printMatrix(vector<vector<int>>& matrix)
{
    for (vector<int> row : matrix)
    {
        for (int elem : row)
        {
            cout << elem << " ";
        }

        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 1, 1, 1},
        {1, 2, 3, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };

    cout << "Printing matrix before nullifying" << endl;

    printMatrix(matrix);

    matrix = zeroMatrix(matrix);

    cout << "Printing matrix after nullifying" << endl;

    printMatrix(matrix);
}
