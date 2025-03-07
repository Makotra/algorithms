#include <iostream>
using namespace std;
bool result(int preorder[],int inorder[],int postorder[],int preorder_start,
             int preorder_end,int inorder_start,int inorder_end, int postorder_start, int postorder_end){
 if (preorder_start>preorder_end or inorder_start>inorder_end or postorder_start>postorder_end){
   return true;
 }
 if (preorder[preorder_start]!=postorder[postorder_end]){
   return false;
 }
 int root=preorder[preorder_start];
 int root1=-1;
 for (int i=inorder_start;i<=inorder_end;i++){
   if (inorder[i]==root){
     root1=i;
     break;
   }
 }
 if (root1==-1){
   return false;
 }
 int left=root1-inorder_start;
 return result(preorder,inorder,postorder,preorder_start+1,preorder_start+left,inorder_start,root1-1,postorder_start,postorder_start+left-1)
        and result(preorder,inorder,postorder,preorder_start+left+1,preorder_end,root1+1,inorder_end,postorder_start+left,postorder_end-1);
};
int main() {
    int num;
    cin>>num;
    int preorder[num], inorder[num],postorder[num];
    for (int i=0;i<num;i++){
      cin>>preorder[i];
    }
    for (int i=0;i<num;i++){
      cin>>inorder[i];
    }
    for (int i=0;i<num;i++){
      cin>>postorder[i];
    }
    if (result(preorder,inorder,postorder,0,num-1,0,num-1,0,num-1)){
      cout<<"YES";
    }
    else{
      cout<<"NO";
    }
    return 0;
}
