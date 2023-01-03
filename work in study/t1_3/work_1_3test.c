#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if (n == 0)
        return;
    if (m == 0)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[i] = nums2[i];
        }
        return;
    }

    int* tmp = (int*)malloc(sizeof(int) * (n + m));
    int topm = 0;
    int topn = 0;
    int topt = 0;
    while (topm < m && topn < n)
    {
        if (nums1[topm] <= nums2[topn])
        {
            tmp[topt] = nums1[topm];
            topt++;
            topm++;
            continue;
        }

        if (nums1[topm] > nums2[topn])
        {
            tmp[topt] = nums2[topn];
            topt++;
            topn++;

        }
    }
    if (topm < m)//跳出循环，如果是nums2结束了的情况
    {
        for (; topm < m; topm++)
        {
            tmp[topt] = nums1[topm];
            topt++;
        }
    }
    if (topn < n)
    {
        for (; topn < n; topn++)
        {
            tmp[topt] = nums2[topn];
            topt++;
        }
    }

    for (int i = 0; i < (n + m); i++)
    {
        nums1[i] = tmp[i];
    }

}