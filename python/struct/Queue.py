""" Queues, by: Zeyu Li """


class Queue:
    """ a queue structure """
    def __init__(self):
        self.items = []
    
    def __str__(self):
        """ overloads print """
        stackAsString = '<Queue>: ['
        if len(self.items) == 0:
            return ''
        elif len(self.items) == 1:
            return self.items[0]
        for item in self.items:
            stackAsString += str(item) + ', '
        return stackAsString[:-2] + "]"
    
    def define(self, items):
        """ defines stack 
        - items must be a list
        """
        if items is list:
            self.items = items
        else:
            raise ValueError("Not a list")
    
    def push(self, item):
        """ c++ push """
        self.items.insert(0, item)
    
    def pop(self):
        """ pop from queue """
        if len(self.items) == 0:
            raise Exception("The queue is empty")
        return self.items.pop()
    
    def peek(self):
        """ looks at first element in queue """
        if len(self.items) == 0:
            raise Exception("The queue is empty")
        return self.items[len(self.items)-1] 
    
    def isEmpty(self):
        """ checks to see if it is empty """
        return self.items == []
    
    def size(self):
        """ looks at length/size queue """
        return len(self.items)
    
    def show(self):
        """ prints entire queue """
        print(self.items)
    
    def clear(self):
        """ clears entire queue """
        self.items = []  
