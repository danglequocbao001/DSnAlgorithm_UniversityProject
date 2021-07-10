# Project _CAUTRUCDULIEU_INT1306_4_

<p align="center">
{ <a href="https://github.com/shanenoi">Nguyễn Ngọc Thanh Danh</a>,
  <a href="https://github.com/danglequocbao001">Đặng Lê Quốc Bảo</a> }<br> <b>N19DCCN027</b> <b>N19DCCN014</b>
</p>
___

# CTDL & GT - Đồ án Quản Lý Thư Viện - PTITHCM - 2021
Thư viện: Ta tổ chức các danh sách sau:
- `Đầu sách` : Danh sách tuyến tính là 1 mảng con trỏ (ISBN , Tên sách, Số trang, Tác giả, năm xuất bản, thể loại, con trỏ dms): con trỏ sẽ trỏ đến các sách thuộc đầu sách tương ứng.
- `Danh mục sách` : Danh sách liên kết đơn( Mã sách,  trạng thái, vị trí   ). Mỗi cuốn sách chỉ có 1 mã duy nhất; trạng thái của sách bao gồm: 0: cho mượn được, 1: đã có độc giả mượn, 2: sách đã thanh lý.
- `Danh sách thẻ độc giả`: Cây nhị phân tìm kiếm (MATHE (số nguyên ngẫu nhiên tự động), Ho, Ten,  Phai, trạng thái của thẻ, con trỏ): con trỏ sẽ trỏ đến danh sách các cuốn sách đã và đang mượn.
- `Danh sách MUONTRA` : danh sách liên kết đơn ( MASACH,  NgayMuon, NgayTra, trạng thái): trạng thái =0 là sách đang mượn (chưa trả), =1 là đã trả, =2 : làm mất sách.

Chương trình có các chức năng sau:
- [x] a {`Danh`, `Bảo`} Nhập thẻ độc giả: thêm / xóa / hiệu chỉnh thông tin thẻ độc giả. Mã thẻ độc giả được chương trình tự động lấy ngẫu nhiên và không trùng với các mã thẻ độc giả cũ; Phái chỉ nhận ‘Nam’ hoặc ‘
Nữ’; trạng thái thẻ = 0 khi thẻ bị khóa, trạng thái thẻ = 1 khi thẻ  đang hoạt động (được quyền mượn sách).
- [x] b {`Danh`} In danh sách độc giả : in ra màn hình theo thứ tự tên+họ tăng dần hoặc theo thứ tự mã độc giả tăng dần theo yêu cầu của thủ thư.
- [x] c {`Danh`} Nhập thông tin đầu sách và đánh mã sách tự động
- [x] d {`Danh`} In danh sách các đầu sách trong thư viện theo từng thể loại, trong từng thể loại thì in theo thứ tự tên sách tăng dần.
- [x] e {`Bảo`} Tìm thông tin sách dựa vào tên sách : in ra các thông tin mã ISBN, tên sách, tác giả, năm xuất bản, thể loại, các mã sách , trạng thái mã sách trong thư viện.
- [x] f {`Bảo`} Mượn sách : nhập vào mã thẻ độc giả, chương trình sẽ liệt kê các sách mà độc giả đang mượn. Mỗi độc giả chỉ được mượn tối đa 3 cuốn, không cho mượn khi giữ 1 sách quá hạn (7 ngày)
- [x] g {`Danh`} Trả sách
- [x] h {`Danh`} Liệt kê danh sách các sách mà 1 độc giả đang mượn
- [x] i {`Bảo`} In danh sách độc giả mượn sách quá hạn theo thứ tự thời gian quá hạn giảm dần
- [x] j {`Bảo`} In 10 sách có số lượt mượn nhiều nhất.
