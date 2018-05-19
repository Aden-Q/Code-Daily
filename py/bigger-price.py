def bigger_price(limit, data):
    """
        TOP most expensive goods
    """
    # your code here
    d={}
    s=[]
    tmp={}
    for i in range(len(data)):
        d[data[i]["price"]]=data[i]["name"]     #generate a new dict which stores price as key and name as value
    h=sorted(d.keys())
    h.reverse()
    for i in range(limit):
        tmp=tmp.copy()         #防止共享引用
        tmp["name"]=d[h[i]]
        tmp["price"]=h[i]
        s.append(tmp)
    return s


if __name__ == '__main__':
    from pprint import pprint
    print('Example:')
    pprint(bigger_price(2, [
        {"name": "bread", "price": 100},
        {"name": "wine", "price": 138},
        {"name": "meat", "price": 15},
        {"name": "water", "price": 1}
    ]))

    # These "asserts" using for self-checking and not for auto-testing
    assert bigger_price(2, [
        {"name": "bread", "price": 100},
        {"name": "wine", "price": 138},
        {"name": "meat", "price": 15},
        {"name": "water", "price": 1}
    ]) == [
        {"name": "wine", "price": 138},
        {"name": "bread", "price": 100}
    ], "First"

    assert bigger_price(1, [
        {"name": "pen", "price": 5},
        {"name": "whiteboard", "price": 170}
    ]) == [{"name": "whiteboard", "price": 170}], "Second"

    print('Done! Looks like it is fine. Go and check it')
