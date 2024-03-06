#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <map>
#include <algorithm>

void print_vec(std::vector<int>& vec){
    std::cout << "vector<int>: ";
    std::for_each(vec.begin(), vec.end(),[](int i){ std::cout << i << " ";});
    std::cout << std::endl;
}

int main(int, char**){
    std::cout << "Hello, from 35_2_filter_unique_num!\n";

    std::vector<int> vec = {1,2,2,3,4,5,5,6,7,8,8,9,0,0,0};

    print_vec(vec);

    auto filter = [](std::vector<int> &v){
        std::map<int, int> my_map;
        std::unordered_set<int> my_set(v.begin(), v.end());

        std::for_each(v.begin(), v.end(), [&my_map, &my_set](int i){
            my_map[i] += my_set.count(i);
        });

        for(auto& record : my_map){
            std::cout << "[" << record.first << "]: " << record.second << std::endl; 
        }

        auto result_ptr = std::make_unique<std::vector<int>>(my_set.begin(), my_set.end());

        return result_ptr;
    };

    auto result = filter(vec);

    print_vec(*result.get());

    return 0;

}
