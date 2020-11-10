

def cost(num_people, budget, prices, beds):
    """
    prices[i] - int price of hotel i
    beds[i][j] - int beds available on weekend j for hotel i.
    """ 
    result = min((prices for prices, num_beds in zip(prices, beds)
                  if any(num > num_people for num in num_beds)),
                 default=None)
    if result:
        result *= num_people
        if result <= budget:
            return result
    return -1
