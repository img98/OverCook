# OVERCOOK

![overcooktitle](https://github.com/user-attachments/assets/1271d9a0-1256-44ef-8e0f-19f959419a6d)

프로젝트 **Overcook**은 현재 서비스 중인 게임 *overcooked*를 모작하여 만든 팀프로젝트입니다.

총 3인의 팀으로 진행하였으며, 게임플레이 및 개발 프레임워크와 인터페이스 작업을 담당했습니다.


# 세부 사항

- 개요 : 친구들과 힘을 합쳐 제한 시간 안에 손님들의 주문대로 요리를 만들어내자.
- 인원구성 : 3명(프로그래밍 2, 아트 1)
- 목적 : GitHub를 사용하여 팀으로 개발하는 방법을 익히고, 게임플레이 프레임워크를 제작하여 실시간 데이터를 관리하고 유저에게 표시하는 인터페이스를 만들었습니다.
- 개발 기간 : 2024.10.15 ~ 2024.11.22

# 컨텐츠 및 기능

## 게임플레이 프레임워크

Entry-Lobby-Stage 구조의 게임플레이 구조를 만들었습니다.

### Entry

게임 시작 시, Entry에 입장하여 유저명을 입력하면 메뉴패널로 시점이 이동합니다.

이러한 카메라 이동은 컨트롤러의 ViewTarget 조정을 통해 구현했으며, 해당 패널 액터의 위젯을 클릭해 새로운 세션을 생성하거나 이미 존재하는 세션에 참가할 수 있습니다.

![entrygif](https://github.com/user-attachments/assets/16a78e8d-fde5-4bf8-a502-fa35017cbe9c)

### Lobby

참가 시에는 방장이 설정한 Lobby의 이름과 해당 세션 내에 참가하고 있는 유저명을 확인할 수 있습니다.

랜덤 세션에만 참가할 수 있던 원작 *overcooked*와는 달리, AdvancedSessions를 사용하여 세션의 이름이나 참여 유저명을 확인하여 선택하는 기능을 추가했습니다.

![sessionname](https://github.com/user-attachments/assets/b65d067a-be1d-4d51-90c6-0dcf1242a2db)

Lobby 에서는 플레이 할 Stage에 대한 정보를 확인할 수 있으며 팀원들과 채팅을 통해 소통하여 Stage를 선택하고 이동합니다.

해당 정보는 실제로 Stage레벨에 전송되며 초기화에 사용됩니다.

![lobbystageinfo](https://github.com/user-attachments/assets/1c50a4cd-501f-466f-9933-f280f8c101e3) |![stageinfo](https://github.com/user-attachments/assets/cf899b7b-572b-4372-b908-3994fb269da5)
--- | --- | 

### Stage

Stage는 Ready-Play-Scoreboard 단계로 구분됩니다.

Ready단계에서는 Level의 초기설정이 진행되며 모든 유저의 입력이 차단됩니다. 스테이지 초기화 및 셋업이 끝났다면 Play단계로 진입합니다.

Play단계에서는 유저들의 입력이 재활성화 되고 남은 시간 타이머, 받을 주문과 같은 게임 기믹이 작동합니다.

제한 시간이 끝나면 Scoreboard 단계로 진입합니다. 모든 유저의 입력이 차단되고 해당 Stage동안 성공적으로 제출한 음식과 실패한 음식, 최종 점수를 표시합니다.

![stageready](https://github.com/user-attachments/assets/73900880-1379-4855-a324-92a0a12828cd) |![stageplay](https://github.com/user-attachments/assets/7c074135-7ade-4ed5-be5c-b29d5e1ae489) |![stagescoreboard](https://github.com/user-attachments/assets/226ddd68-730b-43a3-b0ce-ad969f3dd851)
--- | --- | --- |

결과 발표가 끝나면 다시 Lobby로 돌아오게 됩니다.

Lobby에선 플레이했던 Stage의 점수가 위젯에 표시되며, 결과에 따라 Stage액터 위에 클리어 동상이 표시 됩니다.

위 과정을 반복하며 모든 Stage를 클리어 하는 것이 게임의 목표입니다.

![backscore](https://github.com/user-attachments/assets/a35c43dc-dc9e-4526-bf48-a81d0a2b29d6)

## Lobby 인터페이스 (채팅창, 참가 유저 UI)

세션에 접속하여 Lobby로 이동하면, 현재 접속 중인 모든 유저에게 채팅창으로 새로운 유저의 정보를 알림과 동시에 게임모드는 참여한 유저의 정보를 parsing하여 세션 정보를 업데이트 합니다.

이를 통해 화면 하단의 컨트롤러 UI가 활성화 되어 현재 참가 중인 유저의 수와 이름을 파악할 수 있고, Entry 단계에서 세션을 검색할 때 참가 유저의 이름을 검색 할 수 있습니다.

또한 유저들은 채팅창을 통해 서로 대화하고 플레이 할 다음 선택지를 상의할 수 있습니다.

![lobbyhudgif](https://github.com/user-attachments/assets/46cf1d63-1b66-4586-b3e6-e0ac1c0ae007)

## Stage 플레이 인터페이스

Stage 입장 시, 정해진 시간 동안 랜덤으로 생성되는 주문을 받습니다.

모든 주문은 각자의 제한 시간이 존재하며, 제한 시간 안에 올바른 음식을 제출하면 점수를 획득합니다.

시간 안에 제출하지 못하거나 주문하지 않은 음식을 제출할 경우 점수가 차감 됩니다.

이러한 주문의 종류는 Lobby에 존재하는 Stage액터가 구조체 형태로 보유하고 있습니다. 레벨 이동 간 데이터 유지 방법은 이후에 다룰 'ServerTravel 간 데이터 이동'에서 설명합니다.

StageGameMode는 해당 구조체 내부에 존재하는 ‘생성 될 주문’배열을 확인하고 이 중 랜덤 주문을 GameState에 등록합니다.

GameState의 레시피 리스트에 새롭게 주문이 추가되면 Delegate를 통해 모든 플레이어의 HUD에 표시합니다.

![orderrecipegif](https://github.com/user-attachments/assets/faeb3173-fa64-4011-8e1e-7f26dd2b6dd9)

Stage 시간이 만료되면 플레이 결과를 확인할 수 있습니다.

결과에 표시 될 음식을 성공적으로 제출한 횟수, 실패한 횟수 그리고 최종 획득 점수 등의 데이터는 GameState 내에 변수로 존재합니다. 해당 변수들은 각 음식 제출 성공 혹은 실패 Event와 bind하여 조정합니다.

![scoreboard](https://github.com/user-attachments/assets/6d03eea8-e62a-4178-b915-9d34f84afdef)

## ServerTravel 간 데이터 이동
유저명이나 스테이지 정보와 같은 기능들을 만들기 위해서는 다른 Level의 데이터를 특정 Level까지 유지할 필요가 있었습니다.

그러나 언리얼 엔진의 경우, 레벨을 이동하면 대부분의 오브젝트가 새롭게 생성되기에 해당 데이터들을 저장할 공간이 없었고, 이를 위해 전체 게임 동안 유지되는 GameInstance를 사용하여 데이트를 보관하였습니다.

위 방법을 통해, Lobby의 스테이지 정보를 실제 Stage레벨에 갖고와 적용시킬 수 있으며, 반대로 Stage의 최종 점수를 Lobby로 가져와 스테이지 액터를 업데이트 할 수 있습니다.

# 플레이 영상

[![OVERCOOK시연영상](http://img.youtu.com/vi/oniRT1I7YbA/0.jpg)](https://youtu.be/oniRT1I7YbA)
(이미지 클릭 시, 링크 이동)

> https://youtu.be/oniRT1I7YbA
