# ROS Bridge Client

*Important Note*: as of now, tornado >= 4.5.3 breaks the websocket connection with rosbridge. See [issue](https://github.com/RobotWebTools/rosbridge_suite/issues/371). 
If your connection is dropped at the fist send attempt, check your tornado version with `pip show tornado`.

### TOC

1. [Status](#status)
2. [Usage](#usage) 

<a name="status"></a>

## Status: very early development
All messages that are checked below can be used already. Examples can be found [here](test/full_test.cpp)

| Type           | Message Status | Subscriber Status | Publisher Status |
|----------------|----------------|----------------|----------------|
|**geometry_msgs**| quaternion  | <ul><li>-[x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | quaternion stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | vector3  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | vector3 stamped | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | pose  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | pose 2d   | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | pose array  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | pose with covariance stamped | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | pose stamped | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | pose with covariance  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | point  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | point32  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | point stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | accel  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | accel stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | accel with covariance | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | accel with covariance stamped  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | inertia  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | inertia stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | wrench  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | wrench stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | polygon | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | polygon stamped  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | transform  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | transform stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | twist  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | twist stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | twist with covariance  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | twist with covariance stamped  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|**std_msgs**     | String  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Header  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Int8  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Int8MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Int16  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Int16MultiArray  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Int32  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Int32MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Int64  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Int64MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | UInt8 | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | UInt16  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | UInt16MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | UInt32  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | UInt32MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | UInt64  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | UInt64MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | MultiArrayDimension  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | MultiArrayLayout  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Time  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Byte   | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | ByteMultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Char  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | ColorRGBA  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Duration  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Empty  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Bool  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Float32  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Float32MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Float64  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Float64MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | UInt8MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|**nav_msgs**     | GridCells  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |

<a name="usage"></a>

## Usage



### TODO

- [ ] Actionlib
- [ ] #endifs header guard uint/int
- [ ] make web value json call safer
- [ ] test all wrench stamped constructors
- [ ] Response tesx
