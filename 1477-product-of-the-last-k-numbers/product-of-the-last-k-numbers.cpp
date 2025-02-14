class ProductOfNumbers {
    private:
        vector<int> combinedProduct;

public:
    ProductOfNumbers() {
        combinedProduct.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            combinedProduct = {1};
        }
        else{
            combinedProduct.push_back(combinedProduct.back() * num);
        }

    }
    
    int getProduct(int k) {
        int n = combinedProduct.size();
        if( k >= n ){
            return 0;
        }
        return combinedProduct.back() / combinedProduct[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */