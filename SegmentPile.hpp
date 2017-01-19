#pragma once

#include <vector>
#include <iostream>

template <class T>
class SegmentPile
{
    private:
        std::vector<int> index;
        std::vector<std::pair<int, T>> pile;
    public:
        SegmentPile();
        void allocate(unsigned int start, unsigned int size, T content, int priority = 1);
        int getAllocationIndex(int position);
        std::pair<int, int> getAllocationSegment(int position);
        T get(unsigned int position);
        unsigned int size();
        void print();
};

template <class T>
SegmentPile<T>::SegmentPile()
{

}

template <class T>
void SegmentPile<T>::allocate(unsigned int start, unsigned int size, T content, int priority)
{
    while (index.size() < start + size)
    {
        index.push_back(-1);
    }
    bool canAllocate = true;
    for (int i = start; i < start + size; i++)
    {
        if (index[i] != -1)
        {
            if (pile[index[i]].first > priority)
            {
                std::cout << "Can't allocate in smaller priority" << std::endl;
                canAllocate = false;
                break;
            } 
        }
        else if (index[i] != -1 && getAllocationSegment(index[i]).first < start || getAllocationSegment(index[i]).second > start + size)
        {
            std::cout << getAllocationSegment(index[i]).first << "," << getAllocationSegment(index[i]).second << std::endl;
            std::cout << "Can't allocate in multiple pool" << std::endl;
            canAllocate = false;
            break;
        }
    }
    if (start > 0 && index[start] != -1 && index[start - 1] == index[start]) 
    {
        std::cout << "Can't allocate in left bounded" << std::endl;
        canAllocate = false;
    }
        
    if (start + size < index.size() - 1 && index[start + size] != -1 && index[start + size + 1] == index[start + size])
    {
        std::cout << "Can't allocate in left bounded" << std::endl;
        canAllocate = false;
    }
        
    if (canAllocate)
    {
        int allocIndex = getAllocationIndex(start);
        bool overwriting = (getAllocationSegment(allocIndex).first >= start && getAllocationSegment(allocIndex).second <= start + size);
        if (!overwriting) 
        {
            std::cout << "Overwriting until : " << ((overwriting) ? start + size : index.size()) << std::endl;
            for (int i = 0; i < ((overwriting) ? start + size : index.size()); i++)
            {
                if (index[i] >= allocIndex)
                    index[i] += 1;
            }
        }
        else
        {
            //Sub Segments
        }
        
        std::cout << "I can allocate at index : " << allocIndex << std::endl;
        if (allocIndex >= pile.size()) 
        {
            pile.push_back(std::pair<int, T>(priority, content));
        }
        else
        {
            if (overwriting)
                pile[allocIndex] = std::pair<int, T>(priority, content);
            else
                pile.insert(pile.begin() + allocIndex, std::pair<int, T>(priority, content));
        }
        std::cout << "From : " << start << " to " << start + size << std::endl;
        for (int i = start; i < start + size; i++) {
            std::cout << "Indexing : " << i << " = " << allocIndex << std::endl;
            index[i] = allocIndex;
        } 
            
    }
    else
    {
        std::cout << index[start] << "n" << index[start + size] << std::endl;
        std::cout << "<Error:SegmentPile>[allocate] : Override from " << start << " to " << start + size << " detected, can't merge" << std::endl;
    }
}

template <class T>
int SegmentPile<T>::getAllocationIndex(int position)
{
    int allocationIndex = 0;
    int lastValueIndex = -1;
    for (int i = 0; i < index.size(); i++)
    {
        if (i == position)
            return allocationIndex;
        if (lastValueIndex != index[i] && index[i] != -1)
        {
            lastValueIndex = index[i];
            allocationIndex++;
        }
    }
    return allocationIndex;
}

template <class T>
std::pair<int, int> SegmentPile<T>::getAllocationSegment(int position)
{
    std::pair<int, int> seg = std::pair<int, int>(-1, -1);
    for (int i = 0; i < index.size(); i++)
    {
        if (index[i] == position && seg.first == -1)
            seg = std::pair<int, int>(i, -1);
        else if (index[i] != position && seg.first != -1 && seg.second == -1)
            seg = std::pair<int, int>(seg.first, i);
    }
    if (seg.first != -1 && seg.second == -1)
        seg = std::pair<int, int>(seg.first, index.size() - 1);
    return seg;
}

template <class T>
T SegmentPile<T>::get(unsigned int position)
{
    return pile[position];
}

template <class T>
unsigned int SegmentPile<T>::size()
{
    return pile.size();
}

template <class T>
void SegmentPile<T>::print()
{
    for (int i = 0; i < index.size(); i++)
    {
        std::string sIndex = std::to_string(i);
        if (i < 10) sIndex = "0" + sIndex;
        std::cout << "[" << sIndex << "]";
    }
    std::cout << std::endl;
    for (int i = 0; i < index.size(); i++)
    {
        std::cout << "[" << index[i] << "]";
    }
    std::cout << std::endl;
    for (int i = 0; i < pile.size(); i++)
    {
        std::cout << "[" << i << "] : " << pile[i].second->getType() << std::endl;
    }
}