+ [x] add define to each file in schemas folder
+ [ ] define tree 
+ [x] models
	+ [x] danhmucsach.h
	+ [x] datetime.h
	+ [x] dausach.h
	+ [x] docgia.h
	+ [x] muontra.h
---
+ **General function**:
    + [x] ~~Cast to strings~~
    + [x] Write to file 
    + [x] Read from file 
	+ [x] **Fix**: model casting type `<type, class>`
- **Inheritable methods**:
    - [x] cast (string -> type)
    - [x] cast (type -> string)
	+ [ ] ~~**Each model**: Define convert to its type _Typically: save point using index_~~

- **Base model**
    - [ ] read string (look like for each)
    - [ ] write string (look like for each)
    - [ ] base casting

- **Model for each one**
    - [ ] 2 casting functions

---
- **Notes**:
    - **Load from db**: free old data, create new one (accept lossing data)
    - **Save to db**: For each data write to file
- **Flow**
    - _Read_
    - **Cast string -> type**
    - Thêm xoá sửa các thứ ...
    - **Cast type -> string**
    - _Write_

**Prototype**
 ```c++
Model<LinkedList, DanhMucSachSchema> model = new Model<LinkedList, DanhMucSachSchema>(...);
 ```
