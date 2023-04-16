All of the following are equivalent ways of accessing the array elements:

```c
*(arr + i); scanf("%d", arr + i);    printf("%d", *(arr + i));
 *(i + arr); scanf("%d", i + arr);   printf("%d", *(i + arr));
 arr[i]; scanf("%d", arr[i]);        printf("%d", arr[i]);
 i[arr]; scanf("%d", i[arr]);        printf("%d", i[arr]);
 ```
