# 15강: 언리얼 빌드 시스템

- 강의 목표
  - 언리얼 엔진의 프로젝트 구성과 에디터 동작 방식의 이해
  - 언리얼 엔진의 모듈 시스템을 기반으로 소스 코드를 구성하는 방법의 학습
  - 언리얼 플러그인 시스템을 활용한 효과적인 모듈 구성의 학습
- 강의 과제
  - 탐색기의 빈 폴더로부터 두 개의 모듈, 하나의 플러그인 구조를 가진 언리얼 프로젝트를 직접 제작하고 게임 패키징 까지 수행한 후 그 과정을 정리하시오

## 언리얼 에디터 프로젝트 구성

### 언리얼 에디터 구성

언리얼에서 게임 제작 툴을 말한다면 바로 언리얼 에디터를 의미하는데 이는 게임 제작을 효과적으로 하기 위해서 만들어진 도구이자 툴이다. 언리얼 엔진은 **에디터**와 **게임 빌드**로 구분이 되는데, 에디터는 게임 제작을 위해 제공되는 응용 프로그램으로 우리가 일반적으로 인식하는 언리얼 엔진이다. 게임 빌드는 `EXE`파일과 리소스로 이루어진 독립적으로 동작하는 게임 클라이언트이다.

언리얼 에디터는 게임 개발 작업을 위해 다양한 폴더와 파일 이름 규칙이 미리 설정되어 있다. 정해진 규칙을 잘 파악하고 프로젝트 폴더와 파일을 설정해야 한다. (컨벤션을 준수해야 함)

### 언리얼 에디터의 동작

우리가 개발하게 되는 게임의 한 단위는 프로젝트이며 실제 폴더에 `uproject`라는 확장자를 가진 파일이 존재한다. 이 파일을 클릭하면 에디터가 트리거된다.

- 에디터 실행 방식
  - `uproject` 확장자는 윈도우 레지스트리에 등록되어 있다.
  - `UnrealVersionSelector` 프로그램으로 프로젝트 정보가 넘어감
  - `UnrealVersionSelector`는 런처가 저장한 에디터 정보로부터 버전에 맞는 에디터를 실행 (UnityHub와 비슷한 역할)

### 에디터 버전 정보의 파악

프로젝트 `.uproject` 파일을 텍스트 에디터로 열어보면 `EngineAssociation`이라는 항목이 존재한다. 이 항목은 프로젝트가 사용하는 엔진 버전을 나타낸다. 이 정보를 통해 프로젝트가 사용하는 엔진 버전을 파악할 수 있다. (Json형식)

### 블루프린트 프로젝트

위 방식으로 생성한 프로젝트는 `C++`코드가 없는 언리얼 프로젝트를 의미한다. 이를 **블루프린트 프로젝트**라고 한다. 블루프린트 프로젝트는 `C++`코드를 사용하지 않고 블루프린트로만 게임을 제작하는 프로젝트로 기본 기능만을 활용한다.

언리얼 엔진은 게임 제작에 필요한 기능을 모듈이라는 단위로 제공하고 있으며 언리얼 엔진의 모듈을 상속받아 블루프린트를 활용해 모든 기능과 로직을 구현하는 방식이다.

### 언리얼 C++ 프로젝트

하지만 프로젝트가 커질수록 직접 필요한 모듈을 설계해야 할 순간이 온다. 따라서 직접 C++ 모듈을 제작하여 기본 C++모듈과 블루프린트 사이에 넣어서 더욱 유연한 설계를 할 수 있다. (필요성에 의해)

### 언리얼 C++ 모듈

언리얼 엔진의 소스코드는 모두 **모듈(Module)** 단위로 구성되어 있다. 모듈은 컴파일함으로서 에디터 및 게임에 우리가 제작한 로직을 공급할 수 있다. 모듈 단위로 구성된 C++ 소스 코드를 컴파일한 결과물은 에디터 용으로 DLL 동적라이브러리와 게임용으로는 정적 라이브러리에 해당된다.

에디터 모듈은 항상 `UnrealEditro-{모듈이름}.dll`규칙을 가지고 있다.

### 언리얼 C++ 모듈의 추가

기본 언리얼 모듈에 제작한 C++ 모둘을 추가해 에디터를 띄우고 싶은 경우는 빌드 폴더에 넣어주어야 한다. (윈도우의 경우 `Binaries/Win64`)

`uproject`파일을 열어 `Modules`항목에 추가해주면 된다.

```json
"Modules": [
    {
        "Name": "MyModule",
        "Type": "Runtime",
    }
]
```

*Unity의 Package와 비슷한 역할을 한다.*

### 모듈 C++ 코드의 관리

언리얼 프로젝트가 소스 코드를 관리하는 규칙에 따라 소스 코드 구조를 구성해야 한다. 소스 코드는 멀티 플랫폼 빌드 시스템을 지원하기 위해 특정 프로그램에 종속되어 있지 않다.

실제 빌드를 진행하는 주체는 `UnrealBuildTool`이라는 C# 프로그램이다. `Source` 폴더에 지정된 규칙대로 소스를 넣으면 플랫폼에 맞춰서 알아서 컴파일을 진행

소스코드(Source폴더) -> 빌드툴(UnrealBuildTool) -> 각각 운영체제에 맞는 컴파일러 실행

### Source 폴더의 구조

- Source 폴더
  - **타켓 설정 파일**
  - 모듈 폴더 (보통은 프로젝트 이름으로 모듈 이름을 지정)
    - 모듈 설정 파일
    - 소스 코드 파일 (.h 및 .cpp 파일들)
- 타켓 설정 파일: 전체 솔루션이 다룰 빌드 대상을 지정한다.
  - {프로젝트이름}.Target.cs: 게임 빌드 설정
  - {프로젝트이름}Editor.Target.cs: 에디터 빌드 설정
- 모듈 설정 파일: 모듈을 빌드하기 위한 C++ 프로젝트 설정 정보
  - {모듈이름}.Build.cs: 모듈을 빌드하기 위한 환경 설정

**C#이 가진 유연한 기능을 활용해 런타임에 cs파일을 읽어 빌드 환경을 구축하고 컴파일을 진행한다.**

### 게임 프로젝트의 소스

내가 만든 소스가 게임 프로젝트의 C++ 모듈이 되기 위해 필요한 작업으로 모듈을 구현한, 선언한 헤더와 소스 파일이 있어야 한다. 주로 {모듈이름}.h와 {모듈이름}.cpp로 구성된다.

모듈의 뼈대를 제작하기 위해 매크로를 통해 기본 뼈대 구조를 제작한다.

- IMPLEMENT_MODULE: 일반 모듈
- IMPLEMENT_GAME_MODULE: 게임 모듈
- IMPLEMENT_PRIMARY_GAME_MODULE: 주 게임 모듈

일반적으로 게임 프로젝트는 주 게임 모듈을 하나 선언해야 한다.

모든 준비가 완료되면 `Generate visual studio project files`선택하여 `intermediate`폴더에 프로젝트 관련 파일이 자동으로 생성되게 한다. (해당 폴더를 삭제하면 다시 생성됨)

### 모듈간의 종속 관계

- 모듈 사이에 종속 관계를 설정해 다양한 기능을 구현할 수 있다. (이미 구현되어 있는)
- 우리가 만드는 게임 모듈도 언리얼 엔진이 만든 모듈을 활용해야 한다.
- 언리얼 엔진이 제공하는 모듈 사이에도 종속 관계가 있다.

가장 근본이 되는 모듈은 `Core`라는 모듈이며 `Core`를 기반으로 `CoreUObject`가 빌드업된다. 이외에도 `Json`, `Engine` 등의 모듈이 존재한다.

### 새로운 모듈의 추가

하나의 모듈에 너무 많은 코드가 들어가면 언리얼 엔진은 자동으로 빌드 방식을 변경한다. 그렇기에 프로젝트가 커질 수록 모듈을 나누어서 관리하는 것이 유리하다. (SubModule)

### 모듈의 공개의 참조

모듈 내 소스를 필요한 만큼만 공개해야 모듈 간 의존성을 줄이고 컴파일 타임을 최소화할 수 있다. 따라서 공개할 파일만 public폴더로 두고 숨길 파일들은 모두 private폴더로 두는 것이 좋다.

외부로 공개할 클래스 선언에는 {모듈이름}_DLL 매크로를 붙이면 된다. 게임 모듈에서는 Build.cs 설정을 통해 참조할 모듈을 지정할 수 있다.

### 플러그인 시스템

게임 프로젝트 소스에 모듈을 추가하는 방법은 분업이 어렵기 때문에 모듈만 독립적으로 동작하는 플러그인 구조를 만들어 분업화하는 것이 바람직하다. 서브모듈을 플러그인으로 분리

### 플러그인 구조

플러그인은 다수의 모듈과 게임 콘텐츠를 포함하는 포장 단위로 에디터 설정을 통해 유연하게 플러그인을 추가하거나 삭제할 수 있다. (GAS도 플러그인)

- 플러그인 구조
  - 플러그인 명세서 (uplugin 파일)
  - 플러그인 리소스 (Resource 폴더, 에디터 메뉴용 아이콘)
  - 콘텐츠
  - 모듈 폴더 (즉 위에서 다룬 모듈 구조가 여기서 다시 반복)
- 이러한 플러그인은 마켓 플레이스 판매로도 이어진다.

### 게임 빌드

게임 제작이 완료되면 DLL이 아닌 exe실행 파일이 만들어져야 한다.

- 게임 타켓 설정을 추가하면 게임 빌드 옵션이 추가된다.
- 게임 타켓으로 빌드된 모듈은 정적 라이브러리로 실행 파일에 포함된다.
- 게임이 실행되기 위해서는 실행 파일과 콘텐츠 에셋이 함께 있어야 한다.
- 빌드: 실행 파일을 생성하기 위한 컴파일
- 쿠깅: 지정한 플랫폼에 맞춰 콘텐츠 에셋을 변환하는 작업
- 패키징: 이들을 모아서 하나의 프로그램을 만드는 작업

`Shipping`모드로 빌드하면 게임 실행 파일이 생성된다. 어셔선 매크로는 제외된다.

## 정리

- uproject 명세서를 사용한 언리얼 에디터 동작 원리
- 언리얼 엔진의 모듈 시스템과 소스 코드 관리 방법
- 모듈 작업 분리를 위한 플러그인 시스템
- 언리얼 소스코드의 구조
- 게임 빌드의 설정과 게임 패키징 과정