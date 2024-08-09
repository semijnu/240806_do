4. 테스트 케이스

- 입력값 => 예상 출력값
```cpp
myCar.setBrand("Hyundai");
myCar.setColor("Black");
myCar.setPrice(30000);
myCar.checkInfo(); => "모든 정보가 탑재 되었습니다!"
```

```cpp
myCar.setBrand("Ford");
myCar.setColor("Blue");
myCar.checkInfo(); => "정보가 누락되었습니다! 브랜드, 색상, 가격을 모두 입력하세요!"
```

```cpp
myCar.setBrand("Suzuki");
myCar.setPrice(15000);
myCar.checkInfo(); => "정보가 누락되었습니다! 브랜드, 색상, 가격을 모두 입력하세요!"
```

```cpp
myCar.setColor("White");
myCar.setPrice(40000);
myCar.checkInfo(); => "정보가 누락되었습니다! 브랜드, 색상, 가격을 모두 입력하세요!"
```