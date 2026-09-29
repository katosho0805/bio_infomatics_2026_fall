#include <iostream>
#include <vector>
#include <string>
using namespace std;

double CalcGCContent(string seq){
    double GC_ratio=0.0;
    int GC_count=0;
    for(int i=0;i<seq.size();i++){
        if(seq.at(i)=='G'||seq.at(i)=='C'){
            GC_count++;
        }
    }
    GC_ratio=(double)GC_count/seq.size();
    return GC_ratio;
}

int main(void){
    vector<string> sequences = {
        "ATGCGAT",
        "GCGCGCGC",
        "ATATATAC",
        "CCCGGGTT",
        "TTAACCGA"
    };

    vector<string> high_gc_sequences; 

    for(int i=0;i<sequences.size();i++){
        if(CalcGCContent(sequences.at(i))>=0.5){
            high_gc_sequences.push_back(sequences.at(i));
        }
    }
    
    //この部分を適切に実装せよ。

    //結果の出力
    cout << "GC含量が50%以上の配列：" << endl;
    for(int i = 0; i < high_gc_sequences.size();i++){
        cout << high_gc_sequences[i] << endl;
    }
    return 0;
}