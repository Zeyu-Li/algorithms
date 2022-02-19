""" Doubly Linked List """


class DLinkedListNode:
    # An instance of this class represents a node in Doubly-Linked List
    def __init__(self,initData,initNext,initPrevious):
        self.data = initData
        self.next = initNext
        self.previous = initPrevious
        
        if initNext != None:
            self.next.previous = self
        if initPrevious != None:
            self.previous.next = self
            
    def getData(self):
        return self.data
    
    def setData(self,newData):
        self.data = newData
        
    def getNext(self):
        return self.next
    
    def getPrevious(self):
        return self.previous
    
    def setNext(self,newNext):
        self.next = newNext
        
    def setPrevious(self,newPrevious):
        self.previous = newPrevious


class DLinkedList:
    # An instance of this class represents the Doubly-Linked List
    def __init__(self):
        self.__head=None
        self.__tail=None
        self.__size=0        

    def search(self, item):
        current = self.__head
        found = False
        while current != None and not found:
            if current.getData() == item:
                found= True
            else:
                current = current.getNext()
        return found
        
    def index(self, item):
        current = self.__head
        found = False
        index = 0
        while current != None and not found:
            if current.getData() == item:
                found= True
            else:
                current = current.getNext()
                index = index + 1
        if not found:
                index = -1
        return index        

    def add(self, item):
        # adds an item to list at the beginning
        temp = DLinkedListNode(item, self.__head, None)
        if self.__head != None: #there is a head
            self.__head.setPrevious(temp)
        else: #there is no head & tail
            self.__tail=temp
        self.__head = temp
        self.__size += 1

    def remove(self, item):
        current = self.__head

        # while next is not the end and the current item is not the item we
        # are looking for, cycle through
        while current.getNext() != None and current.getData() != item:
            current = current.getNext()

        # if not the end, set the next node to be linked to the previous node of the one removed
        # else, it is the end, so tail must be changed to reflect it
        if current.getNext() != None:
            current.getNext().setPrevious(current.getPrevious())
        else:
            self.__tail = current.getPrevious()
            self.__tail.setNext(None)

        # likewise to the one above
        if current.getPrevious() != None:
            current.getPrevious().setNext(current.getNext())
        else:
            self.__head = current.getItem()
            self.__head.setPrevious(None)

        self.__size -= 1

        
    def append(self, item):
        # adds the item to the end of the list
        # must traverse the list to the end and add item
        temp = DLinkedListNode(item, None, None)
        if (self.__head == None):
            self.__head=temp
        else:
            self.__tail.setNext(temp)
            temp.setPrevious(self.__tail)

        self.__tail=temp
        self.__size +=1
        
    def insert(self, pos, item):
        # inserts item at position pos
        assert 0 <= pos < self.__size, "pop postition out of range"

        if pos == 0:
            self.add(item)
            return
        elif pos == self.__size:
            self.append(item)
            return
        # insert middle
        else:
            current = self.__head
            for i in range(pos - 1):
                if self.index(current.getData()) == pos:
                    break
                current = current.getNext()
            
            new_node = DLinkedListNode(item, current.getNext(), current)
            current.getNext().setPrevious(new_node)

            self.__size += 1
        
    def pop1(self):
        # pops the last element
        assert self.__tail != None, "Nothing to pop"
        last = self.__tail.getData()

        # check special case for 1 element in linked list
        if self.__tail.getPrevious() != None:
            self.__tail = self.__tail.getPrevious()
            self.__tail.setNext(None)
        else:
            self.__tail = None
            self.__head = None

        self.__size -= 1
        return last
    
    def pop(self, pos=None):
        # incorporate pop1 when no pos argument is given
        if pos == None:
            return self.pop1()
        else:
            assert 0 <= pos < self.__size, "pop postition out of range"
            
            current = self.__head
            for i in range(pos):
                if self.index(current.getData()) == pos:
                    break
                current = current.getNext()

            # if in the middle, set previous to point to next and vise versa
            if current.getNext() != None and current.getPrevious() != None:
                current.getPrevious().setNext(current.getNext())
                current.getNext().setPrevious(current.getPrevious())

            # if head end, set next node's previous to none and head to next
            elif current.getNext() != None and current.getPrevious() == None:
                current.getNext().setPrevious(None)
                self.__head = current.getNext()

            # if tail end, set previous node's ptr to none and tail to previous
            else:
                current.getPrevious().setNext(None)
                self.__tail = current.getPrevious()

        self.__size -= 1
        return current.getData()


    def searchLarger(self, item):
        # returns the position of the first 
        # element that is larger than item, or -1 if
        # there is no larger item. 

        current = self.__head
        # run through the whole list and if the current is greater then item, 
        # then return it, otherwise, return -1
        for i in range(self.__size):
            if current.getData() > item:
                return i
            current = current.getNext()
        return -1
        
    def getSize(self):
        return self.__size
    
    def getItem(self, pos):
        # intis postion to account for negative postions
        pos = (pos + self.__size) % self.__size
        assert pos < self.__size, "Index out of bound"

        index = self.index(self.__head.getData())
        current = self.__head
        while pos != index:
            current = current.getNext()
            index += 1

        return current.getData()

        
    def __str__(self):
        # returns a string representation of the list
        current = self.__head
        string = ''
        while current != None:
            string += str(current.getData())+' '
            current = current.getNext()
        return string.strip()
