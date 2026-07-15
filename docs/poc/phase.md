# DataMonitor 구현 계획

1. DataPersistence 저장소(JSON) 읽기 연동
2. 주문량확인 구현 - 상태별(RESERVED/CONFIRMED/PRODUCING/RELEASE) 주문 수 집계 및 표시 (REJECTED 제외)
3. 재고량확인 구현 - 시료별 재고 수량 표시, 주문 대비 상태(여유/부족/고갈) 판정 로직
4. 생산현황/대기주문 조회 구현 - 생산중인 시료 정보 및 생산큐(FIFO) 목록 표시
