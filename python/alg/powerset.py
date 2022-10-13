'''
Power set natively
Description: based on https://stackoverflow.com/a/1482320/12539335
'''

def powerset(iterator: list) -> list:
    x = len(iterator)
    masks = [1 << i for i in range(x)]
    res = []
    for i in range(1 << x):
        res.append([ss for mask, ss in zip(masks, iterator) if i & mask])

    return res