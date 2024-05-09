# MSP ROS

Launch and parameter files for [adr_autopilot](https://github.com/UTAT-ADR/adr_autopilot/).

Use the latest Betaflight config file in [hardware](https://github.com/UTAT-ADR/hardware).

Check quad mass, thrust_max, omega_max before flight.

Thrust ratio:
* Old iFlight props: 0.96
* Gemfan red props: 0.97

To launch Vicon & Betaflight IMU fusion as localization:
```
roslaunch msp_ros run_adrmsp_agiros_imu.launch
```

To launch base station:
```
roslaunch msp_ros run_adrmsp_basecomputer.launch
```

Takeoff procedure:
* Thrust ratio
* Connect
* Data recording
* Arm
* Arm Bridge
* MSP Override
* Start
