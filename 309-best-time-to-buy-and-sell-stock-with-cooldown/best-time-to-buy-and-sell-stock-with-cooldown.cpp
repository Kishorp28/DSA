class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy = -prices[0];
        int sell = 0;
        int cool = 0;

        for(int i = 1 ; i < prices.size() ; i++){

            int prevbuy = buy;
            int prevsell = sell;
            int prevcool = cool;

            buy = max(prevbuy, prevcool - prices[i]);
            sell = prevbuy + prices[i];
            cool = max(prevsell,prevcool);
        }
        return max(sell,cool);
        
    }
};