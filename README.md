* FWLib v3.5.0

- 13.12.04
1. SDIO를 이용한 SDHCI Low Level 정상동작 확인 완료
: ST에서 제공하는 Library에 SDIO CLK의 Divider 상수가 잘 못 설정 되어 있음.

2. Makefile에 flash-bin 추가
: make flash-bin 란 명령어를 사용하면 OpenOCD를 이용(내수 Script을 이용)하여 
Flash를 자동으로 Write함.

- 13.12.10
1. FatFs v0.10 프로젝트에 포함
: SDIO를 이용한 LowLevel driver 포팅 완료

- 13.12.16
: stm_eval_sdio_sd.* => stm_sdio_sd.* 이름 변경
: FatFs Library 설정파일 변경 및 f_write() 함수 동작 확인
: main.h에 string.h 파일 참조하게 함, stm32f1_s133.h에 STM_EVAL_COMInit() 함수 선언함

- 13.12.18
: makefile 수정, FatLib도 같이 clean과 build될 수 있도록 규칙 추가

- 14.04.17
: LCD 초기화 코드 적용 및 기본적인 API 추가
