    // while((*all) -> next -> next)
    // {
    //     if((*all) -> next -> next -> stack > (*all) -> stack)
    //     {
    //         big = (*all) -> next -> next -> stack;
    //         head = (*all) -> next -> next -> next -> stack;
    //     }
    //     *all = (*all) -> next -> next;
    // }
    /*?????????????????????????????????????????????????????????????????????????*/
    /*?????????????????????????????????????????????????????????????????????????*/
    // t_nvr *node = x.sorts;
    // while(x.sorts)
    // {
    //     printf("%d\n", x.sorts -> stack);
    //     x.sorts = x.sorts -> next;
    // }
    // x.sorts = node;
    // printf("-----\n");
    // printf("=====\n");
    // long_inc_subs(&lst, last, &x.sorts);
    // while(x.sorts)
    // {
    //     printf("%d\n", x.sorts -> stack);
    //     x.sorts = x.sorts -> next;
    // }
//     void find_it(t_nvr **tab , int kk)
// {
//     while((*tab))
//     {
//         if((*tab) -> stack == kk){
//             (*tab) = (*tab) -> next;
//             printf("%d\n", tab -> stack);
//             break;
//         }
//         (*tab) = (*tab) -> next;
//     }
// }
// -------
//     int y;
//     int m;
//     t_nvr *head;
    
//     t_nvr *save = NULL;
//     m = 1;
//     int x = 1;
//     y = ft_lstsize(*sta);
//     head = *sta;
//    // kk = find_next(*sta,kk,y);
//     while(x <= y)
//     {
//         // while(m <= y)
//         // {
//             if((*sta) -> stack == kk)
//             {
//                 *sta = head;
//                 check_and_rotate(&*sta,&*stb,(*sta) -> stack);
//                 //mkk = find_longest(*sta);
//                 printf("--%d\n", kk);
//                 kk = find_next(*sta,kk,y);
//                 printf("%d\n", kk);
//                 break;
//             }
//             (*sta) = (*sta) -> next;
//             // m++;
//         // }
//         //*sta = head;
//        // m = 1;
//         x++;
//     }
//     return save;
// ----------------------------------
// int find_small(t_nvr *arr)
// {
//     int min;
 
//     min = arr -> stack;
//     while (arr)
//     {
//         if(arr -> stack < min)
//             min = arr -> stack;
//         arr = arr -> next;   
//     }
//     return (min);
// }
// ----------------------------------
// ----------------------------------

    
// }
// int find_next(t_nvr *sta, int kk, int x)
// {
//     t_nvr *reg;
//     t_nvr *last;
//     int a;
    
//     reg = sta;
//     a = 0;
//     last = link_lst(&sta);
//     find_it(&sta, kk, x);
//     while(a < x)
//     {
//         if(sta -> stack > kk)
//         {
//             kk = sta -> stack;
//             while (sta -> stack != last -> stack)
//                 sta = sta -> next;
//             sta -> next = NULL;
//             sta = reg;
//             return kk;
//         }
//         sta = sta -> next;
//         a++;
//     }
//     while (sta -> stack != last -> stack)
//     sta = sta -> next;
//     sta -> next = NULL;
//     sta = reg;
//     return (1);
// }

// t_nvr *sort_stacks(t_nvr **sta, t_nvr **stb, int kk)
// {
//     t_nvr   *node;
//     t_nvr   *reg;
//     int     size;
//     int     y;
//     int     x;

//     size = ft_lstsize(*sta); 
//     reg = (*sta);
//     x = 0;
//     while(x < size)
//     {
//         node = (*sta) -> next;
//         y = x + 1;
//         while(y < size)
//         {
//             if(node -> stack < kk)
//             {
//                 check_and_rotate(&*sta,&*stb,node -> stack);
//                 kk = find_next(*sta, kk,size);
//                 break;
//             }
//             node = node -> next;
//             y++;
//         }
//         (*sta) = (*sta) -> next;
//         x++;
//         //break;
//     }
//     // while((*sta))
//     // {
//     //     printf("%d\n", (*sta) -> stack);
//     //     (*sta) = (*sta) -> next;
//     // }
//     return reg;   
// }
// ----------------------------------
// ----------------------------------
// void ft_ft(t_nvr **sta, t_nvr **stb, t_nvr *index, int kk)
// {
//     int x = 1;
//     int size = ft_lstsize(index);
    
//     while(x <= size)
//     {
//         if(x != index -> stack)
//         {
//             check_and_rotate(&*sta,&*stb,kk);
//             index = sort_stacks(&*sta, kk);
// 			sort()
// 			// while(index)
// 			// {
// 			// 	printf(" -> %d <-\n", index -> stack);
// 			// 	index = index -> next;
// 			// }
//         }
//         index = index -> next;
//         x++;
//     }
// }



// void sort_a(t_nvr **sta, t_nvr **stb,int kk)
// {
//     t_nvr *head = NULL;
//     t_nvr *node;
//     t_nvr *reg = *sta;
//     t_nvr *last;
//     int a = 0;
//     int b;
//     int size1 = ft_lstsize(*stb);
//     int size = ft_lstsize(*sta);
//     if(size1 > 0)
//     size1 = 0;
        
    
//     last = link_lst(&*sta);
//     find_it(&*sta,kk,size);
//     printf("%d\n", (*sta) -> stack);
//     head = (*sta);
//     while(a < size)
//     {
//         node = head -> next;
//         b = a + 1;
//         while(b < size)
//         {
//             if(node -> stack > kk)
//             {
//                 kk = node -> stack;
//                 check_and_rotate(&*stb,&*sta,kk,'b');
//                 break;
//             }
//             b++;
//             node = node -> next;
//         }
//         head = head -> next;
//         a++;
//     }
//     while ((*sta) -> stack != last -> stack)
//         (*sta) = (*sta) -> next;
//     (*sta) -> next = NULL;
//     (*sta) = reg;
// }