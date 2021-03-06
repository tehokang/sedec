[![Build Status](https://travis-ci.com/tehokang/sedec.svg?token=tukzKYpBaAzTzcPeGfcg&branch=master)](https://travis-ci.com/tehokang/sedec)

# What is sedec?
The sedec(=SEction coDEC) is a library to encode/decode and also transcode section(ISO-13818),<br>
Especially for AIT(=Application Information Table) of HbbTV 1.5/2.0.

The input of sedec is raw AIT table(Not section to be seperated) <br>
And output is abstractive AIT object.
User application can achieve all of information that AIT has.

# Architecture
## - Class diagram (ASAP)
![screenshot](https://github.com/tehokang/sedec/blob/master/sedec_class_diagram.png)

# How to build
Build tree are compose of followings:
```
.
├── CMakeLists.txt
├── LICENSE
├── README.md
├── build (Directory you will may create)
├── examples (This has samples of decoder/encoder)
├── release (Directory to release to cross platforms)
└── sedec(Sedec sources)
```

You can meet library(libsedec) in build/out directory after following build commands.<br>
And thus there are examples, e.g. decoder, encoder.

```
#mkdir build
#cd build
#cmake ..
#make
```

# How to port your project
Please follow below examples 

# Examples
## Decoder
There is executable binary to decode AIT(table, not section) in build/out
You can output result of AIT information like following.
```
#cd build/out
#decoder_example ./example_ait.dump
[main                ]***************************
[main                ]* Section Decoding Sample *
[main                ]***************************

[PrintSection        ]= AIT Section's raw information is followings =====
[PrintSection        ]table_id : 0x74
[PrintSection        ]section_syntax_indicator : 0x1
[PrintSection        ]section_length : 0x3bd (957)
[PrintSection        ]test_application_flag : 0x0
[PrintSection        ]application_type : 0x0010
[PrintSection        ]version_number : 0x0
[PrintSection        ]current_next_indicator : 1
[PrintSection        ]section_number : 0x0
[PrintSection        ]last_section_number : 0x0
[PrintSection        ]common_descriptors_length : 0x0 (0)
[PrintSection        ]application_loop_length : 0x3b0 (944)
[PrintSection        ]
====== [0] Application list ======
[PrintApplication    ]organization_id : 0x00000013
[PrintApplication    ]application_id : 0x0001
[PrintApplication    ]application_control_code : 0x1
[PrintApplication    ]application_descriptors_loop_length : 0x5c (92)
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x02 (transport_protocol_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x20
[PrintDescriptor     ]	protocol_id : 3
[PrintDescriptor     ]	transport_protocol_label : 0
[PrintDescriptor     ]	URL_base_length : 0x1b (27)
[PrintDescriptor     ]	URL_base_byte : http://itv.ard.de/ardstart/
[PrintDescriptor     ]	URL_extension_count : 0x0
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x02 (transport_protocol_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x5
[PrintDescriptor     ]	protocol_id : 1
[PrintDescriptor     ]	transport_protocol_label : 1
[PrintDescriptor     ]	remote_connection : 0
[PrintDescriptor     ]	component_tag : 14
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x00 (application_descriptor)
[PrintDescriptor     ]	descriptor_length : 0xa
[PrintDescriptor     ]	application_profiles_length : 0x5
[PrintDescriptor     ]	application_profile : 0x0000
[PrintDescriptor     ]	version_major : 0x01
[PrintDescriptor     ]	version_minor : 0x01
[PrintDescriptor     ]	version_micro : 0x01
[PrintDescriptor     ]	service_bound_flag : 0
[PrintDescriptor     ]	visibility : 3
[PrintDescriptor     ]	application_priority : 2
[PrintDescriptor     ]	transport_protocol_label[0] : 0
[PrintDescriptor     ]	transport_protocol_label[1] : 1
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x01 (application_name_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x19
[PrintDescriptor     ]	ISO_639_languahe_code[0] : 0x64(d)
[PrintDescriptor     ]	ISO_639_languahe_code[1] : 0x65(e)
[PrintDescriptor     ]	ISO_639_languahe_code[2] : 0x75(u)
[PrintDescriptor     ]	application_name_length : 0x15
[PrintDescriptor     ]	application_name : HBBTV-Start-DSMCC+Web
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x15 (simple_application_location_descriptor)
[PrintDescriptor     ]	descriptor_length : 0xa
[PrintDescriptor     ]	initial_path_bytes : index.html
[PrintDescriptor     ]
[PrintSection        ]======================================
[PrintSection        ]
====== [1] Application list ======
[PrintApplication    ]organization_id : 0x00000013
[PrintApplication    ]application_id : 0x0002
[PrintApplication    ]application_control_code : 0x2
[PrintApplication    ]application_descriptors_loop_length : 0x3f (63)
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x02 (transport_protocol_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x1e
[PrintDescriptor     ]	protocol_id : 3
[PrintDescriptor     ]	transport_protocol_label : 2
[PrintDescriptor     ]	URL_base_length : 0x19 (25)
[PrintDescriptor     ]	URL_base_byte : http://itv.ard.de/ardepg/
[PrintDescriptor     ]	URL_extension_count : 0x0
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x00 (application_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x9
[PrintDescriptor     ]	application_profiles_length : 0x5
[PrintDescriptor     ]	application_profile : 0x0000
[PrintDescriptor     ]	version_major : 0x01
[PrintDescriptor     ]	version_minor : 0x01
[PrintDescriptor     ]	version_micro : 0x01
[PrintDescriptor     ]	service_bound_flag : 0
[PrintDescriptor     ]	visibility : 3
[PrintDescriptor     ]	application_priority : 5
[PrintDescriptor     ]	transport_protocol_label[0] : 2
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x01 (application_name_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x7
[PrintDescriptor     ]	ISO_639_languahe_code[0] : 0x64(d)
[PrintDescriptor     ]	ISO_639_languahe_code[1] : 0x65(e)
[PrintDescriptor     ]	ISO_639_languahe_code[2] : 0x75(u)
[PrintDescriptor     ]	application_name_length : 0x3
[PrintDescriptor     ]	application_name : EPG
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x15 (simple_application_location_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x9
[PrintDescriptor     ]	initial_path_bytes : index.php
[PrintDescriptor     ]
[PrintSection        ]======================================
[PrintSection        ]
====== [2] Application list ======
[PrintApplication    ]organization_id : 0x00000013
[PrintApplication    ]application_id : 0x0003
[PrintApplication    ]application_control_code : 0x2
[PrintApplication    ]application_descriptors_loop_length : 0x70 (112)
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x02 (transport_protocol_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x2c
[PrintDescriptor     ]	protocol_id : 3
[PrintDescriptor     ]	transport_protocol_label : 3
[PrintDescriptor     ]	URL_base_length : 0x27 (39)
[PrintDescriptor     ]	URL_base_byte : http://hbbtv.ardmediathek.de/hbbtv-ard/
[PrintDescriptor     ]	URL_extension_count : 0x0
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x00 (application_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x9
[PrintDescriptor     ]	application_profiles_length : 0x5
[PrintDescriptor     ]	application_profile : 0x0000
[PrintDescriptor     ]	version_major : 0x01
[PrintDescriptor     ]	version_minor : 0x01
[PrintDescriptor     ]	version_micro : 0x01
[PrintDescriptor     ]	service_bound_flag : 1
[PrintDescriptor     ]	visibility : 3
[PrintDescriptor     ]	application_priority : 5
[PrintDescriptor     ]	transport_protocol_label[0] : 3
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x01 (application_name_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x17
[PrintDescriptor     ]	ISO_639_languahe_code[0] : 0x64(d)
[PrintDescriptor     ]	ISO_639_languahe_code[1] : 0x65(e)
[PrintDescriptor     ]	ISO_639_languahe_code[2] : 0x75(u)
[PrintDescriptor     ]	application_name_length : 0x13
[PrintDescriptor     ]	application_name : HBBTV ARD-Mediathek
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x15 (simple_application_location_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x1c
[PrintDescriptor     ]	initial_path_bytes : mediathek/?devicegroup=hbbtv
[PrintDescriptor     ]
[PrintSection        ]======================================
[PrintSection        ]
====== [3] Application list ======
[PrintApplication    ]organization_id : 0x00000013
[PrintApplication    ]application_id : 0x0005
[PrintApplication    ]application_control_code : 0x2
[PrintApplication    ]application_descriptors_loop_length : 0x42 (66)
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x02 (transport_protocol_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x1e
[PrintDescriptor     ]	protocol_id : 3
[PrintDescriptor     ]	transport_protocol_label : 4
[PrintDescriptor     ]	URL_base_length : 0x19 (25)
[PrintDescriptor     ]	URL_base_byte : http://www.tagesschau.de/
[PrintDescriptor     ]	URL_extension_count : 0x0
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x00 (application_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x9
[PrintDescriptor     ]	application_profiles_length : 0x5
[PrintDescriptor     ]	application_profile : 0x0000
[PrintDescriptor     ]	version_major : 0x01
[PrintDescriptor     ]	version_minor : 0x01
[PrintDescriptor     ]	version_micro : 0x01
[PrintDescriptor     ]	service_bound_flag : 0
[PrintDescriptor     ]	visibility : 3
[PrintDescriptor     ]	application_priority : 5
[PrintDescriptor     ]	transport_protocol_label[0] : 4
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x01 (application_name_descriptor)
[PrintDescriptor     ]	descriptor_length : 0xe
[PrintDescriptor     ]	ISO_639_languahe_code[0] : 0x64(d)
[PrintDescriptor     ]	ISO_639_languahe_code[1] : 0x65(e)
[PrintDescriptor     ]	ISO_639_languahe_code[2] : 0x75(u)
[PrintDescriptor     ]	application_name_length : 0xa
[PrintDescriptor     ]	application_name : Tagesschau
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x15 (simple_application_location_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x5
[PrintDescriptor     ]	initial_path_bytes : hbbtv
[PrintDescriptor     ]
[PrintSection        ]======================================
[PrintSection        ]
====== [4] Application list ======
[PrintApplication    ]organization_id : 0x00000013
[PrintApplication    ]application_id : 0x0014
[PrintApplication    ]application_control_code : 0x2
[PrintApplication    ]application_descriptors_loop_length : 0x4e (78)
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x02 (transport_protocol_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x1e
[PrintDescriptor     ]	protocol_id : 3
[PrintDescriptor     ]	transport_protocol_label : 5
[PrintDescriptor     ]	URL_base_length : 0x19 (25)
[PrintDescriptor     ]	URL_base_byte : http://hbbtv.daserste.de/
[PrintDescriptor     ]	URL_extension_count : 0x0
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x00 (application_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x9
[PrintDescriptor     ]	application_profiles_length : 0x5
[PrintDescriptor     ]	application_profile : 0x0000
[PrintDescriptor     ]	version_major : 0x01
[PrintDescriptor     ]	version_minor : 0x01
[PrintDescriptor     ]	version_micro : 0x01
[PrintDescriptor     ]	service_bound_flag : 1
[PrintDescriptor     ]	visibility : 3
[PrintDescriptor     ]	application_priority : 5
[PrintDescriptor     ]	transport_protocol_label[0] : 5
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x01 (application_name_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x16
[PrintDescriptor     ]	ISO_639_languahe_code[0] : 0x64(d)
[PrintDescriptor     ]	ISO_639_languahe_code[1] : 0x65(e)
[PrintDescriptor     ]	ISO_639_languahe_code[2] : 0x75(u)
[PrintDescriptor     ]	application_name_length : 0x12
[PrintDescriptor     ]	application_name : Mediathek DasErste
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x15 (simple_application_location_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x9
[PrintDescriptor     ]	initial_path_bytes : index.php
[PrintDescriptor     ]
[PrintSection        ]======================================
[PrintSection        ]
====== [5] Application list ======
[PrintApplication    ]organization_id : 0x00000013
[PrintApplication    ]application_id : 0x001b
[PrintApplication    ]application_control_code : 0x2
[PrintApplication    ]application_descriptors_loop_length : 0x4b (75)
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x02 (transport_protocol_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x19
[PrintDescriptor     ]	protocol_id : 3
[PrintDescriptor     ]	transport_protocol_label : 6
[PrintDescriptor     ]	URL_base_length : 0x14 (20)
[PrintDescriptor     ]	URL_base_byte : http://hbbtv.ndr.de/
[PrintDescriptor     ]	URL_extension_count : 0x0
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x00 (application_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x9
[PrintDescriptor     ]	application_profiles_length : 0x5
[PrintDescriptor     ]	application_profile : 0x0000
[PrintDescriptor     ]	version_major : 0x01
[PrintDescriptor     ]	version_minor : 0x01
[PrintDescriptor     ]	version_micro : 0x01
[PrintDescriptor     ]	service_bound_flag : 1
[PrintDescriptor     ]	visibility : 3
[PrintDescriptor     ]	application_priority : 5
[PrintDescriptor     ]	transport_protocol_label[0] : 6
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x01 (application_name_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x17
[PrintDescriptor     ]	ISO_639_languahe_code[0] : 0x64(d)
[PrintDescriptor     ]	ISO_639_languahe_code[1] : 0x65(e)
[PrintDescriptor     ]	ISO_639_languahe_code[2] : 0x75(u)
[PrintDescriptor     ]	application_name_length : 0x13
[PrintDescriptor     ]	application_name : HBBTV NDR-Mediathek
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x15 (simple_application_location_descriptor)
[PrintDescriptor     ]	descriptor_length : 0xa
[PrintDescriptor     ]	initial_path_bytes : index.html
[PrintDescriptor     ]
[PrintSection        ]======================================
[PrintSection        ]
====== [6] Application list ======
[PrintApplication    ]organization_id : 0x00000013
[PrintApplication    ]application_id : 0x0023
[PrintApplication    ]application_control_code : 0x2
[PrintApplication    ]application_descriptors_loop_length : 0x5a (90)
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x02 (transport_protocol_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x33
[PrintDescriptor     ]	protocol_id : 3
[PrintDescriptor     ]	transport_protocol_label : 7
[PrintDescriptor     ]	URL_base_length : 0x2e (46)
[PrintDescriptor     ]	URL_base_byte : http://www.br-online.de/mediathek-video-hbbtv/
[PrintDescriptor     ]	URL_extension_count : 0x0
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x00 (application_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x9
[PrintDescriptor     ]	application_profiles_length : 0x5
[PrintDescriptor     ]	application_profile : 0x0000
[PrintDescriptor     ]	version_major : 0x01
[PrintDescriptor     ]	version_minor : 0x01
[PrintDescriptor     ]	version_micro : 0x01
[PrintDescriptor     ]	service_bound_flag : 0
[PrintDescriptor     ]	visibility : 3
[PrintDescriptor     ]	application_priority : 5
[PrintDescriptor     ]	transport_protocol_label[0] : 7
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x01 (application_name_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x10
[PrintDescriptor     ]	ISO_639_languahe_code[0] : 0x64(d)
[PrintDescriptor     ]	ISO_639_languahe_code[1] : 0x65(e)
[PrintDescriptor     ]	ISO_639_languahe_code[2] : 0x75(u)
[PrintDescriptor     ]	application_name_length : 0xc
[PrintDescriptor     ]	application_name : BR-Mediathek
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x15 (simple_application_location_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x6
[PrintDescriptor     ]	initial_path_bytes : br.php
[PrintDescriptor     ]
[PrintSection        ]======================================
[PrintSection        ]
====== [7] Application list ======
[PrintApplication    ]organization_id : 0x00000013
[PrintApplication    ]application_id : 0x0038
[PrintApplication    ]application_control_code : 0x2
[PrintApplication    ]application_descriptors_loop_length : 0x52 (82)
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x02 (transport_protocol_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x22
[PrintDescriptor     ]	protocol_id : 3
[PrintDescriptor     ]	transport_protocol_label : 8
[PrintDescriptor     ]	URL_base_length : 0x1d (29)
[PrintDescriptor     ]	URL_base_byte : http://hbbtv.sr-mediathek.de/
[PrintDescriptor     ]	URL_extension_count : 0x0
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x00 (application_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x9
[PrintDescriptor     ]	application_profiles_length : 0x5
[PrintDescriptor     ]	application_profile : 0x0000
[PrintDescriptor     ]	version_major : 0x01
[PrintDescriptor     ]	version_minor : 0x01
[PrintDescriptor     ]	version_micro : 0x01
[PrintDescriptor     ]	service_bound_flag : 1
[PrintDescriptor     ]	visibility : 3
[PrintDescriptor     ]	application_priority : 5
[PrintDescriptor     ]	transport_protocol_label[0] : 8
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x01 (application_name_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x16
[PrintDescriptor     ]	ISO_639_languahe_code[0] : 0x64(d)
[PrintDescriptor     ]	ISO_639_languahe_code[1] : 0x65(e)
[PrintDescriptor     ]	ISO_639_languahe_code[2] : 0x75(u)
[PrintDescriptor     ]	application_name_length : 0x12
[PrintDescriptor     ]	application_name : HbbTV SR Mediathek
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x15 (simple_application_location_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x9
[PrintDescriptor     ]	initial_path_bytes : index.php
[PrintDescriptor     ]
[PrintSection        ]======================================
[PrintSection        ]
====== [8] Application list ======
[PrintApplication    ]organization_id : 0x00000013
[PrintApplication    ]application_id : 0x001f
[PrintApplication    ]application_control_code : 0x2
[PrintApplication    ]application_descriptors_loop_length : 0x6a (106)
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x02 (transport_protocol_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x2c
[PrintDescriptor     ]	protocol_id : 3
[PrintDescriptor     ]	transport_protocol_label : 9
[PrintDescriptor     ]	URL_base_length : 0x27 (39)
[PrintDescriptor     ]	URL_base_byte : http://hbbtv.ardmediathek.de/hbbtv-swr/
[PrintDescriptor     ]	URL_extension_count : 0x0
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x00 (application_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x9
[PrintDescriptor     ]	application_profiles_length : 0x5
[PrintDescriptor     ]	application_profile : 0x0000
[PrintDescriptor     ]	version_major : 0x01
[PrintDescriptor     ]	version_minor : 0x01
[PrintDescriptor     ]	version_micro : 0x01
[PrintDescriptor     ]	service_bound_flag : 1
[PrintDescriptor     ]	visibility : 3
[PrintDescriptor     ]	application_priority : 5
[PrintDescriptor     ]	transport_protocol_label[0] : 9
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x01 (application_name_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x11
[PrintDescriptor     ]	ISO_639_languahe_code[0] : 0x64(d)
[PrintDescriptor     ]	ISO_639_languahe_code[1] : 0x65(e)
[PrintDescriptor     ]	ISO_639_languahe_code[2] : 0x75(u)
[PrintDescriptor     ]	application_name_length : 0xd
[PrintDescriptor     ]	application_name : SWR Mediathek
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x15 (simple_application_location_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x1c
[PrintDescriptor     ]	initial_path_bytes : mediathek/?devicegroup=hbbtv
[PrintDescriptor     ]
[PrintSection        ]======================================
[PrintSection        ]
====== [9] Application list ======
[PrintApplication    ]organization_id : 0x00000013
[PrintApplication    ]application_id : 0x0058
[PrintApplication    ]application_control_code : 0x2
[PrintApplication    ]application_descriptors_loop_length : 0x5a (90)
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x02 (transport_protocol_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x23
[PrintDescriptor     ]	protocol_id : 3
[PrintDescriptor     ]	transport_protocol_label : a
[PrintDescriptor     ]	URL_base_length : 0x1e (30)
[PrintDescriptor     ]	URL_base_byte : http://programm-origin.ard.de/
[PrintDescriptor     ]	URL_extension_count : 0x0
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x00 (application_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x9
[PrintDescriptor     ]	application_profiles_length : 0x5
[PrintDescriptor     ]	application_profile : 0x0000
[PrintDescriptor     ]	version_major : 0x01
[PrintDescriptor     ]	version_minor : 0x01
[PrintDescriptor     ]	version_micro : 0x01
[PrintDescriptor     ]	service_bound_flag : 0
[PrintDescriptor     ]	visibility : 3
[PrintDescriptor     ]	application_priority : 5
[PrintDescriptor     ]	transport_protocol_label[0] : a
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x01 (application_name_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x14
[PrintDescriptor     ]	ISO_639_languahe_code[0] : 0x64(d)
[PrintDescriptor     ]	ISO_639_languahe_code[1] : 0x65(e)
[PrintDescriptor     ]	ISO_639_languahe_code[2] : 0x75(u)
[PrintDescriptor     ]	application_name_length : 0x10
[PrintDescriptor     ]	application_name : HBBTV CouchModus
[PrintDescriptor     ]
[PrintDescriptor     ]
[PrintDescriptor     ]	descriptor_tag : 0x15 (simple_application_location_descriptor)
[PrintDescriptor     ]	descriptor_length : 0x12
[PrintDescriptor     ]	initial_path_bytes : couchmodus/tv.html
[PrintDescriptor     ]
[PrintSection        ]======================================
[PrintSection        ]checksum_CRC32 : 0x1483f568
[PrintSection        ]======================================
```

## Encoder
This encoder's real operation is to trascode from original AIT to modified AIT.  <br>
The way to run same as decoder example, but it has to check sources how example can transcode original AIT.
```
#encoder_example original_ait
#decoder_example modified_ait // you can see information if transcoding work out well.
```

# TODO
<del>Class diagram </del> : Done <br>
<del>Block diagram </del> : Not need to make, cus of simple architecture
