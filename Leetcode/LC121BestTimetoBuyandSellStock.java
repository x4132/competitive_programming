public class LC121BestTimetoBuyandSellStock {
    public int maxProfit(int[] prices) {
        int minBuy = 10001;
        int maxProfit = -1;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < minBuy) minBuy = prices[i];
            if (maxProfit < prices[i] - minBuy) maxProfit = prices[i] - minBuy;
        }

        return maxProfit;
    }
}
