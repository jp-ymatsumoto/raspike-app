# raspike-app

# 設計図

## 日本語

### クラス図

```mermaid
classDiagram
  class 実行モード {
    <<enumeration>>
    未定義
    スタート指示の待機中
    走行中
  }
  class hackspi {
    実行モード モード = 未定義
    +初期化() void
    +走行する() void
    -hackspi_run_undefined() void
    -hackspi_run_starter() void
    -hackspi_run_tracer() void
  }

  class スターター {
    +初期化() void
    +押下状態を取得する() bool_t
  }

  class 車輪 {
    +初期化() void
    +回転する() void
    +停止する() void
  }

  hackspi -- 実行モード
  hackspi "1"--"2" スターター
  hackspi "1"--"1" 車輪
  車輪 "1"--"2" モーター
```

### シーケンス図

```mermaid
sequenceDiagram
  周期タスク->>hackspi: 走行する
  opt スタート指示の待機中
    hackspi->>スターター: 押下状態を取得する
  end
  opt 走行中
    hackspi->>車輪: 回転する
  end
```

## 英語

### クラス図

```mermaid
classDiagram
  class run_mode {
    <<enumeration>>
    RUN_UNDEFINED
    RUN_STARTER
    RUN_TRACER
  }
  class hackspi {
    run_mode mode = RUN_UNDEFINED
    +hackspi_init() void
    +hackspi_run() void
    -hackspi_run_undefined() void
    -hackspi_run_starter() void
    -hackspi_run_tracer() void
  }

  class starter {
    +starter_init() void
    +starter_is_pressed() bool_t
  }

  class wheel {
    +wheel_init() void
    +wheel_run() void
    +wheel_stop() void
  }

  hackspi -- run_mode
  hackspi "1"--"2" starter
  hackspi "1"--"1" wheel
  wheel "1"--"2" motor
```
