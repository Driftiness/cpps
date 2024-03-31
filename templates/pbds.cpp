#include<chrono>
#include<ext/pb_ds/assoc_container.hpp>
const int RANDOM = std::chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {inline int operator()(int x)const {return x ^RANDOM;}};
__gnu_pbds::gp_hash_table<int,int,chash>table;

int main()
{
    return 0;
}