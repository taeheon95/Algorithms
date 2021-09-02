#include <iostream>
#include <stdlib.h>
#include <vector>

using std::vector;
using namespace std;

//vector로 n-정사각행렬을 만들고 각 원소를 i+j라고 한다.
void MatrixInit(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = i + j;
        }
    }
}

void printMat(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/** 
 * @brief 행렬 A와 B를 더하여 C에 저장시키는 함수 (A,B,C는 전부 같은 크기이다.)
 * @param A 
 * @param B
 * @param C 
 * @return 없음
 */
void MatrixSum(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB, vector<vector<int>> &matrixC)
{
    for (int i = 0; i < matrixA.size(); i++)
    {
        for (int j = 0; j < matrixA.size(); j++)
        {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

/**
 * @brief 행렬 A에서 B를 빼서 C에 저장하는 함수
 */
void MatrixSub(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB, vector<vector<int>> &matrixC)
{
    for (int i = 0; i < matrixA.size(); i++)
    {
        for (int j = 0; j < matrixA.size(); j++)
        {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

/**
 * @brief 행렬 A와 B를 곱하여 C에 저장하는 함수
 * @param (A, B, C) 행렬
 * @return 없음
 */
void MatrixMul(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB, vector<vector<int>> &matrixC)
{
    for (int i = 0; i < matrixA.size(); i++)
    {
        for (int j = 0; j < matrixA.size(); j++)
        {
            for (int k = 0; k < matrixA.size(); k++)
            {
                matrixC[i][j] = matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

/**
 * @brief 행렬을 나누는 함수(4개의 부분으로)
 * @param mainMatrix, 나눌 행렬
 * @param subMatrix(A, B, C, D) 저장할 행렬 공간 4개
 * @return 없음
 */
void SubMatrix(vector<vector<int>> &mainMatrix, vector<vector<int>> &subMatrixA, vector<vector<int>> &subMatrixB, vector<vector<int>> &subMatrixC, vector<vector<int>> &subMatrixD)
{
    int newNum = subMatrixA.size();

    for (int i = 0; i < newNum; i++)
    {
        for (int j = 0; j < newNum; j++)
        {
            subMatrixA[i][j] = mainMatrix[i][j];
            subMatrixB[i][j] = mainMatrix[i][j + newNum];
            subMatrixC[i][j] = mainMatrix[i + newNum][j];
            subMatrixD[i][j] = mainMatrix[i + newNum][j + newNum];
        }
    }
}

/**
 * @brief 행렬을 재결합 해주는 함수
 * @param mainMatrix 합친 결과를 저장해주는 행렬
 * @param subMatrix(A,B,C,D) 부분 행렬
 * @return 없음
 */
void MergeMatrix(vector<vector<int>> &mainMatrix, vector<vector<int>> subMatrixA, vector<vector<int>> subMatrixB, vector<vector<int>> subMatrixC, vector<vector<int>> subMatrixD)
{
    int newNum = subMatrixA.size();

    for (int i = 0; i < newNum; i++)
    {
        for (int j = 0; j < newNum; j++)
        {
            mainMatrix[i][j] = subMatrixA[i][j];
            mainMatrix[i][j + newNum] = subMatrixB[i][j];
            mainMatrix[i + newNum][j] = subMatrixC[i][j];
            mainMatrix[i + newNum][j + newNum] = subMatrixD[i][j];
        }
    }
}

/**
 * @brief 쉬트라센 알고리즘 함수
 * @param n 행렬의 사이즈
 * @param matrixA
 * @param matrixB
 * @param matrixC 결과가 저장될 곳
 * @return 없음
 */
void Strassen(int n, vector<vector<int>> matrixA, vector<vector<int>> matrixB, vector<vector<int>> matrixC)
{
    if (n <= 2)
    {
        MatrixMul(matrixA, matrixB, matrixC);
        return;
    }
    else
    {
        int newRow = n / 2;
        vector<int> newCol(newRow, 0);

        // A와 B의 부분 행렬
        vector<vector<int>> a11(newRow, newCol), a12(newRow, newCol), a21(newRow, newCol), a22(newRow, newCol);
        vector<vector<int>> b11(newRow, newCol), b12(newRow, newCol), b21(newRow, newCol), b22(newRow, newCol);

        // 스트라센의 부분행렬 연산 결과를 저장하는 행렬
        vector<vector<int>> m1(newRow, newCol);
        vector<vector<int>> m2(newRow, newCol);
        vector<vector<int>> m3(newRow, newCol);
        vector<vector<int>> m4(newRow, newCol);
        vector<vector<int>> m5(newRow, newCol);
        vector<vector<int>> m6(newRow, newCol);
        vector<vector<int>> m7(newRow, newCol);
        //

        // a11~b22의 연산결과들을 입시로 저장할 행렬
        vector<vector<int>> tempA(newRow, newCol);
        vector<vector<int>> tempB(newRow, newCol);
        //

        // m1~m7 연산 결과로 C를 구하기 위해 저장할 행렬
        vector<vector<int>> c11(newRow, newCol);
        vector<vector<int>> c12(newRow, newCol);
        vector<vector<int>> c21(newRow, newCol);
        vector<vector<int>> c22(newRow, newCol);
        //

        // A를 4개로, B를 4개로
        SubMatrix(matrixA, a11, a12, a21, a22);
        SubMatrix(matrixB, b11, b12, b21, b22);

        // 재귀로
        // m1 = (a11 + a22)(b11 + b22)
        MatrixSum(a11, a22, tempA);
        MatrixSum(b11, b22, tempB);
        Strassen(newRow, tempA, tempB, m1);

        // m2 = (a21 + a22)b11
        MatrixSum(a21, a22, tempA);
        Strassen(newRow, tempA, b11, m2);

        // m3 = a11(b12-b22)
        MatrixSub(b12, b22, tempB);
        Strassen(newRow, a11, tempB, m3);

        // m4 = a22(b21-b11)
        MatrixSub(b21, b11, tempB);
        Strassen(newRow, a22, tempB, m4);

        // m5 = (a11+a12)b22
        MatrixSum(a11, a12, tempA);
        Strassen(newRow, tempA, b22, m5);

        // m6 = (a21-a11)(b11+b12)
        MatrixSub(a21, a11, tempA);
        MatrixSum(b11, b12, tempB);
        Strassen(newRow, tempA, tempB, m6);

        // m7 = (a12-a22)(b12-b22)
        MatrixSub(a12, a22, tempA);
        MatrixSub(b12, b22, tempB);
        Strassen(newRow, tempA, tempB, m7);

        // c11 = m1 + m4 - m5 + m7
        MatrixSum(m1, m4, tempA);    // tempA = m1 + m4;
        MatrixSum(tempA, m7, tempB); // tempB = m1 + m4 + m7;
        MatrixSub(tempB, m5, c11);   // c11 = m1 + m4 - m5 + m7;

        // c12 = m3 + m5
        MatrixSum(m3, m5, c12);

        // c21 = m2 + m4
        MatrixSum(m2, m4, c21);

        // c22 = m1 + m3 - m2 + m6
        MatrixSum(m1, m3, tempA);
        MatrixSum(tempA, m6, tempB);
        MatrixSub(tempB, m2, c22);

        MergeMatrix(matrixC, c11, c12, c21, c22);
    }
}

int main()
{
    int n = 0;
    cout << "정사각 행렬의 크기를 입력하시오:";
    cin >> n;

    int Row = n;
    int Col = n;

    vector<vector<int>> A(Row, vector<int>(Col, 0)); // A[Row][Col] 인 동적 배열
    vector<vector<int>> B(Row, vector<int>(Col, 0)); // B[Row][Col] 인 동적 배열
    vector<vector<int>> C(Row, vector<int>(Col, 0)); // C[Row][Col] 인 동적 배열

    MatrixInit(A, n);
    MatrixInit(B, n);

    Strassen(n, A, B, C);

    printMat(A, n);
    printMat(B, n);
    printMat(C, n);

    return 0;
}