# DataMonitor PRD

## 개요
현재 저장된 시료/주문 데이터 상태를 콘솔에서 실시간 조회하는 관리자 도구.

## 요구사항
- 주문량확인 : 상태별(RESERVED / CONFIRMED / PRODUCING / RELEASE) 주문 수 표시, REJECTED는 집계에서 제외
- 재고량확인 : 시료별 현재 재고 수량 표시, 주문 대비 재고 상태 표기(여유 / 부족 / 고갈)
- 생산현황 조회 : 현재 생산중인 시료 정보 및 생산큐(FIFO 대기열) 목록 표시
- DataPersistence가 저장한 JSON 데이터를 읽어와 표시 (직접 수정하지 않음)
