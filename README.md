# HDH_Bankeralgorithm
Chương trình được xây dựng bằng ngôn ngữ C++ để minh họa giải thuật banker để phát hiện và giải quết deadlock

Chương trình của nhóm có các chức năng như: xét trạng thái an toàn của hệ thống và có thể yêu cầu tài nguyên của tiến trình ( Request ).
# Hướng dẫn sử dụng
Chương trình của nhóm có các chức năng như: xét trạng thái an toàn của hệ thống và có thể yêu cầu tài nguyên của tiến trình ( Request ).
Khi chạy code người dung sẽ được màn hình như sau, cho phép người dùng nhập số lượng tài nguyên (Resource)  , số lượng tiến trình (Process), nhập trạng thái tài nguyên ban đầu (Available) nhập bảng Max và Allocation. 
 
 ![image](https://user-images.githubusercontent.com/73542040/123397533-b87a4e80-d5cc-11eb-9ac3-4cf99c62356b.png)
 
Sau khi  nhập xong mọi thứ chương trình sẽ tiến hành xét trạng thái an toàn của  hệ thống nếu trạng thái an toàn chương trình sẽ xuất ra cái trạng thái đã chọn và đường đi của trạng thái an toàn. 

![image](https://user-images.githubusercontent.com/73542040/123398210-756cab00-d5cd-11eb-8b00-d07adc23a56f.png)

Ngược lại nếu hệ thống không tìm được trạng thái an toàn chương trình sẽ xuất ra thông báo không có trạng thái an toàn xảy ra Deadlock.

![image](https://user-images.githubusercontent.com/73542040/123398508-d4cabb00-d5cd-11eb-9aae-0ab7ecce8683.png)
 
Sau khi đã xét trạng thái an toàn bên phải màn hình sẽ xuất hiện Menu với 3 lựa chọn : 1.Yêu cầu tài nguyên ( Request ) 2.làm bài khác 3.Exit
Khi chọn 2.Làm bài khác chương trình sẽ trở lại trang ban đầu để nhập dữ liệu của bài toán khác, chọn 3.Exit để tắt chương trình, còn khi nhập 1.Yêu cầu tài nguyên ( Request ) chương trình sẽ có phép bạn chọn tiến trình muốn yêu cầu (Process)  và tài nguyên cần yêu cầu (Request Resource).
 
![image](https://user-images.githubusercontent.com/73542040/123398605-edd36c00-d5cd-11eb-953f-41b5fdff8cd3.png)

Sau khi nhập tiến trình và tài nguyên cần yêu cầu chương trình sẽ tính và cho ra trạng thái mới sau khi tiến trình được yêu cầu tài nguyên và sau đó sẽ xét trạng thái an toàn của trái thái mới ,nếu trạn thái an toàn chương trình sẽ thông báo các tiến trình được chọn theo thứ tự và đường đi của trạng thái an toàn.
 
![image](https://user-images.githubusercontent.com/73542040/123398744-122f4880-d5ce-11eb-8ab4-5480421aea6b.png)
 
Nếu không có trạng thái an toàn thì chương trình sẽ thông báo không có trạng thái an toàn tiến trình yêu cầu ko được đáp ứng, đồng thời phục hồi lại trạng thái ban đầu.

![image](https://user-images.githubusercontent.com/73542040/123398802-21ae9180-d5ce-11eb-874b-44736479029e.png)
 
Nếu tiến trình được yêu cầu có tài nguyên quá lớn (Request resource > Need or Available ) thì chương trình sẽ thông báo và không nhận Request đó

![image](https://user-images.githubusercontent.com/73542040/123398852-2ecb8080-d5ce-11eb-8fd1-96c4d4784f7a.png)



 
