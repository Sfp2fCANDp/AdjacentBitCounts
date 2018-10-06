#include <iostream>
#include <bitset>
#include <map>
#include <vector>
#include <string>
#define K 4


int AdjBC(std::string binString, int k);

int generateGrayarr(int n)
{
    // base case
    if (n <= 0)
        return 0;

    int result = 0;
    // 'arr' will store all generated codes
    std::vector<std::string> arr;

    // start with one-bit pattern
    arr.push_back("0");
    arr.push_back("1");

    // Every iteration of this loop generates 2*i codes from previously
    // generated i codes.
    int i, j;
    for (i = 2; i < (1<<n); i = i<<1)
    {
        // Enter the prviously generated codes again in arr[] in reverse
        // order. Nor arr[] has double number of codes.
        for (j = i-1 ; j >= 0 ; j--)
            arr.push_back(arr[j]);

        // append 0 to the first half
        for (j = 0 ; j < i ; j++)
            arr[j] = "0" + arr[j];

        // append 1 to the second half
        for (j = i ; j < 2*i ; j++)
            arr[j] = "1" + arr[j];
    }

    // print contents of arr[]
    for (i = 0 ; i < arr.size() ; i++ )
    {
        if (AdjBC(arr[i], 2) == K)
        {
            ++result;
        }
        //std::cout << arr[i] << std::endl;
    }

    return result;
}

int AdjBC(std::string binString, int k)
{
    int result = 0;
    int increment = 0;
    char x;
    int j = 0;
    for (int iter = 1; binString[iter] != '\0'; iter++)
    {
        j = iter;
        //std::cout << "binString.at(j) = " << binString.at(j) << '\n';
        //x = binString.at(--iter);


        if ((binString.at(--j) == '1') && (binString.at(iter) == '1'))
        {
            ++increment;
            if(increment == (k-1))
            {
                --increment;
                ++result;
            }
        }
        else if (binString.at(iter) == '0' || binString.at(iter) == '\0')
        {
            increment = 0;
        }
    }

    return result;
}

int main() {

    int x = 0;
    for (int i = 3; i < 20; i++)
    {
        x = generateGrayarr(i);

        std::cout << x << '\n';
    }
    //generateGrayarr(6);

    //P = number of DATASETS that follow

//    int p;
//    std::cin >> p;
//    std::cout << "\n";
//
//    //k = number of adjacent bit count
//    int k;
//    //n = number of bits in string && n < 100
//    int n;
//
//    std::map<int, int> nk;
//    std::map<int, int>:: const_iterator it;
//
//    for (int iter = 1; iter <= p; iter++)
//    {
//        std::cin >> n;
//        std::cin >> k;
//        std::cout << iter << " " << n << " " << k << "\n";
//        nk[n] = k;
//        for (it = nk.begin(); it!= nk.end(); it++)
//        {
//            std::cout << it->first<<" =>"<< it->second<<std::endl;
//            std::cout << AdjBC(it->first, it->second);
//        }
//    }
}