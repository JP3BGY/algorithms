#include <cstdio>
#include <random>
using namespace std;
int main(int argc, char const* argv[])
{
  random_device rng;
  uniform_int_distribution<size_t> dist(1,1000000);
  int V=dist(rng),E=dist(rng);
  printf("%d %d\n",V,E);
  fprintf(stderr, "%d %d\n",V,E);
  uniform_int_distribution<size_t> dist2(1,V),distpm(0,1);
  for (int i = 0; i < E; i++) {
    int p=dist2(rng),q=dist2(rng);
    if(distpm(rng)==0){
      p=-p;
    }
    if(distpm(rng)==0){
      q=-q;
    }
    printf("%d %d\n",p,q);
  }
  return 0;
}
