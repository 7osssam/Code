#### All of the following are equivalent ways of accessing the array elements:

```c
*(arr + i); 
scanf("%d", arr + i);    printf("%d", *(arr + i));
```

```c
*(i + arr);
scanf("%d", i + arr);   printf("%d", *(i + arr));
```

```c
arr[i];
scanf("%d", &arr[i]);        printf("%d", arr[i]);
```

```c
i[arr];
scanf("%d", &i[arr]);        printf("%d", i[arr]);
```
