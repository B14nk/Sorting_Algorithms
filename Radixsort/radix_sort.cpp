#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using u32    = uint_least32_t; 
using engine = std::mt19937;

int get_max_digits(std::vector<int> input){
    int max = 0;
    int result = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (max < input[i])
        {
            max = input[i];
        }
    }

    while (max != 0)
    {
        max = max / 10;
        result += 1;
    }
    return result;
}

void count_sort(std::vector<int> &input, int &exp){
    int n = input.size();
    std::vector<int> output;
    output.resize(n);
    int count[10] = {0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < n; i++)
    {
        count[(input[i]/exp)%10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }

    for (int i = n-1; i >= 0; i--)
    {
        output[count[(input[i]/exp)%10]-1] = input[i];
        count[(input[i]/exp)%10]--;
    }

    input = output;  
    return;
}

void radix_sort(std::vector<int> &input){
    int max_digits = get_max_digits(input);
    int exp = 1;
    for (int i = 0; i < max_digits; i++)
    {
        count_sort(input, exp);

        exp = exp*10;
    }
    return;
}

std::vector<int> create_rand_vector(){
    std::vector<int> input;

    srand(time(0));

    for (int i = 0; i < 1000000; i++)
    {
        input.push_back(rand());
    }

    return input;
}

int main(int argc, char const *argv[])
{
    std::vector<int> input = create_rand_vector();

    // std::cout<< "input: ";
    // for (int i = 0; i < input.size(); i++)
    // {
    //     std::cout<<input[i]<<" ";
    // }
    // std::cout<<std::endl;

    auto start = std::chrono::system_clock::now();

    radix_sort(input);

    auto end = std::chrono::system_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "time: " << elapsed.count() << "ns\n";



    // std::cout<< "output: ";
    // for (int i = 0; i < input.size(); i++)
    // {
    //     std::cout<<input[i]<<" ";
    // }
    // std::cout<<std::endl;
    
    return 0;
}
