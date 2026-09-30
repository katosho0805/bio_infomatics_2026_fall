#include <iostream>
#include <vector>
#include <ctime>   // time.hとほぼ同機能
using namespace std;

void f1(vector<int> data){ // 何もしない関数（値渡し）
  return;
}
void f2(vector<int>& data){ // 何もしない関数（参照渡し）
  return;
}

int main(void){
  int vector_size = 1e7;                     // 1000万要素
  vector<int> temp_vector(vector_size, 0);

  clock_t start = clock();
  f1(temp_vector);
  clock_t end = clock();
  cout << "time:" << (double)(end - start)/CLOCKS_PER_SEC << endl;

  start = clock();
  f2(temp_vector);
  end = clock();
  cout << "time:" << (double)(end - start)/CLOCKS_PER_SEC << endl;
  return 0;
}

//time:0.030298,0.029143,0.030209
//time:1e-06,2e-06,2e-06

//値渡しの場合、呼ばれるたびにvectorを丸ごとコピーするため、
//値渡しと参照では、これほどに実行時間に差が生じる。

//追記：実行時間が毎回ブレる理由は、コンピューターのメモリの状況などが関係するから。
//値渡しと参照の使い分け
//int やdoubleなど,小さい型で変更しないもの←値渡し
//vector・string・クラスなど大きいもので、読むだけ←　const参照
//呼び出し元の変数を、関数の中で書き換えたい←参照
//大きいものを、関数の中で加工したいが、元は残したい←値渡し

