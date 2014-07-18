  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (RaspPiPilot_P)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% RaspPiPilot_P.CompareToConstant3_const
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_P.DrawShapes1_lineWidth
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RaspPiPilot_P.DrawMarkers2_size
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% RaspPiPilot_P.BlobAnalysis_minArea
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% RaspPiPilot_P.DrawMarkers2_color
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_P.CompareToConstant_const
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 12;
	
	  ;% RaspPiPilot_P.CompareToConstant2_const
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 13;
	
	  ;% RaspPiPilot_P.CompareToConstant1_const
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 14;
	
	  ;% RaspPiPilot_P.CompareToConstant1_const_l
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 15;
	
	  ;% RaspPiPilot_P.CompareToConstant1_const_p
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 16;
	
	  ;% RaspPiPilot_P.CompareToConstant4_const
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 17;
	
	  ;% RaspPiPilot_P.CompareToConstant5_const
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 18;
	
	  ;% RaspPiPilot_P.CompareToConstant2_const_e
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 19;
	
	  ;% RaspPiPilot_P.CompareToConstant_const_l
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% RaspPiPilot_P.Gain3_Gain
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_P.SubtractImageCentre_Bias
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_InitialSta
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 3;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_Coefficien
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 4;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_InitialS_e
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 16;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_Coeffici_a
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 17;
	
	  ;% RaspPiPilot_P.Convertpixelstodegrees_Gain
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 29;
	
	  ;% RaspPiPilot_P.Gain4_Gain
	  section.data(8).logicalSrcIdx = 21;
	  section.data(8).dtTransOffset = 30;
	
	  ;% RaspPiPilot_P.Constant_Value
	  section.data(9).logicalSrcIdx = 22;
	  section.data(9).dtTransOffset = 31;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_InitialS_b
	  section.data(10).logicalSrcIdx = 23;
	  section.data(10).dtTransOffset = 32;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_Coeffici_h
	  section.data(11).logicalSrcIdx = 24;
	  section.data(11).dtTransOffset = 33;
	
	  ;% RaspPiPilot_P.Convertpixelstodegrees1_Gain
	  section.data(12).logicalSrcIdx = 25;
	  section.data(12).dtTransOffset = 47;
	
	  ;% RaspPiPilot_P.Gain6_Gain
	  section.data(13).logicalSrcIdx = 26;
	  section.data(13).dtTransOffset = 48;
	
	  ;% RaspPiPilot_P.Constant1_Value
	  section.data(14).logicalSrcIdx = 27;
	  section.data(14).dtTransOffset = 49;
	
	  ;% RaspPiPilot_P.Constant_Value_f
	  section.data(15).logicalSrcIdx = 28;
	  section.data(15).dtTransOffset = 50;
	
	  ;% RaspPiPilot_P.Gain2_Gain
	  section.data(16).logicalSrcIdx = 29;
	  section.data(16).dtTransOffset = 51;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_InitialS_p
	  section.data(17).logicalSrcIdx = 30;
	  section.data(17).dtTransOffset = 52;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_Coeffici_b
	  section.data(18).logicalSrcIdx = 31;
	  section.data(18).dtTransOffset = 53;
	
	  ;% RaspPiPilot_P.Gain1_Gain
	  section.data(19).logicalSrcIdx = 32;
	  section.data(19).dtTransOffset = 67;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_InitialS_f
	  section.data(20).logicalSrcIdx = 33;
	  section.data(20).dtTransOffset = 68;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_Coeffic_hi
	  section.data(21).logicalSrcIdx = 34;
	  section.data(21).dtTransOffset = 69;
	
	  ;% RaspPiPilot_P.Gain_Gain
	  section.data(22).logicalSrcIdx = 35;
	  section.data(22).dtTransOffset = 83;
	
	  ;% RaspPiPilot_P.Constant_Value_k
	  section.data(23).logicalSrcIdx = 36;
	  section.data(23).dtTransOffset = 84;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_InitialS_a
	  section.data(24).logicalSrcIdx = 37;
	  section.data(24).dtTransOffset = 85;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_Coeffic_he
	  section.data(25).logicalSrcIdx = 38;
	  section.data(25).dtTransOffset = 86;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_InitialS_k
	  section.data(26).logicalSrcIdx = 39;
	  section.data(26).dtTransOffset = 98;
	
	  ;% RaspPiPilot_P.GeneratedFilterBlock_Coeffici_i
	  section.data(27).logicalSrcIdx = 40;
	  section.data(27).dtTransOffset = 99;
	
	  ;% RaspPiPilot_P.Constant1_Value_d
	  section.data(28).logicalSrcIdx = 41;
	  section.data(28).dtTransOffset = 111;
	
	  ;% RaspPiPilot_P.Constant2_Value
	  section.data(29).logicalSrcIdx = 42;
	  section.data(29).dtTransOffset = 112;
	
	  ;% RaspPiPilot_P.Constant3_Value
	  section.data(30).logicalSrcIdx = 43;
	  section.data(30).dtTransOffset = 113;
	
	  ;% RaspPiPilot_P.Constant4_Value
	  section.data(31).logicalSrcIdx = 44;
	  section.data(31).dtTransOffset = 114;
	
	  ;% RaspPiPilot_P.Constant5_Value
	  section.data(32).logicalSrcIdx = 45;
	  section.data(32).dtTransOffset = 115;
	
	  ;% RaspPiPilot_P.Constant6_Value
	  section.data(33).logicalSrcIdx = 46;
	  section.data(33).dtTransOffset = 116;
	
	  ;% RaspPiPilot_P.Memory_X0
	  section.data(34).logicalSrcIdx = 47;
	  section.data(34).dtTransOffset = 117;
	
	  ;% RaspPiPilot_P.Constant_Value_p
	  section.data(35).logicalSrcIdx = 48;
	  section.data(35).dtTransOffset = 118;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% RaspPiPilot_P.Memory_X0_j
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_P.Constant_Value_d
	  section.data(2).logicalSrcIdx = 50;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% RaspPiPilot_P.UnitDelay_InitialCondition
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_P.Constant_Value_o
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (RaspPiPilot_B)
    ;%
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% RaspPiPilot_B.Constant3
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_B.Constant4
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RaspPiPilot_B.Constant5
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RaspPiPilot_B.Constant6
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% RaspPiPilot_B.roll
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% RaspPiPilot_B.pitch
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% RaspPiPilot_B.Sum1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% RaspPiPilot_B.GeneratedFilterBlock
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% RaspPiPilot_B.GeneratedFilterBlock_o
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% RaspPiPilot_B.Sum
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% RaspPiPilot_B.X
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 11;
	
	  ;% RaspPiPilot_B.SubtractImageCentre
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% RaspPiPilot_B.Convertpixelstodegrees
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 17;
	
	  ;% RaspPiPilot_B.BlobAnalysis1_o2
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% RaspPiPilot_B.Gain4
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 21;
	
	  ;% RaspPiPilot_B.MathFunction
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 23;
	
	  ;% RaspPiPilot_B.DataTypeConversion1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% RaspPiPilot_B.Product1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 25;
	
	  ;% RaspPiPilot_B.MathFunction2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 26;
	
	  ;% RaspPiPilot_B.DataTypeConversion
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 27;
	
	  ;% RaspPiPilot_B.Product
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 28;
	
	  ;% RaspPiPilot_B.Sum5
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 29;
	
	  ;% RaspPiPilot_B.Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 30;
	
	  ;% RaspPiPilot_B.DataTypeConversion_l
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 31;
	
	  ;% RaspPiPilot_B.MatrixConcatenate
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 32;
	
	  ;% RaspPiPilot_B.TrigonometricFunction
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 40;
	
	  ;% RaspPiPilot_B.avgIntensity
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 41;
	
	  ;% RaspPiPilot_B.TmpSignalConversionAtSFunctionI
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 42;
	
	  ;% RaspPiPilot_B.navOn
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% RaspPiPilot_B.DataTypeConversion_d
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_B.WhileIterator
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RaspPiPilot_B.id1
	  section.data(3).logicalSrcIdx = 31;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RaspPiPilot_B.BlobAnalysis_o1
	  section.data(4).logicalSrcIdx = 32;
	  section.data(4).dtTransOffset = 3;
	
	  ;% RaspPiPilot_B.bbox_largest
	  section.data(5).logicalSrcIdx = 33;
	  section.data(5).dtTransOffset = 19;
	
	  ;% RaspPiPilot_B.length
	  section.data(6).logicalSrcIdx = 34;
	  section.data(6).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% RaspPiPilot_B.result
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_B.messageId
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RaspPiPilot_B.DrawMarkers2_o1
	  section.data(3).logicalSrcIdx = 37;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RaspPiPilot_B.DrawMarkers2_o2
	  section.data(4).logicalSrcIdx = 38;
	  section.data(4).dtTransOffset = 76802;
	
	  ;% RaspPiPilot_B.DrawMarkers2_o3
	  section.data(5).logicalSrcIdx = 39;
	  section.data(5).dtTransOffset = 153602;
	
	  ;% RaspPiPilot_B.dataOut
	  section.data(6).logicalSrcIdx = 40;
	  section.data(6).dtTransOffset = 230402;
	
	  ;% RaspPiPilot_B.lengthOut
	  section.data(7).logicalSrcIdx = 41;
	  section.data(7).dtTransOffset = 230658;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% RaspPiPilot_B.Compare
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_B.DataTypeConversion2
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RaspPiPilot_B.DataTypeConversion1_k
	  section.data(3).logicalSrcIdx = 44;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RaspPiPilot_B.Compare_c
	  section.data(4).logicalSrcIdx = 45;
	  section.data(4).dtTransOffset = 3;
	
	  ;% RaspPiPilot_B.Compare_j
	  section.data(5).logicalSrcIdx = 47;
	  section.data(5).dtTransOffset = 7;
	
	  ;% RaspPiPilot_B.Compare_b
	  section.data(6).logicalSrcIdx = 52;
	  section.data(6).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 4;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (RaspPiPilot_DW)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% RaspPiPilot_DW.GeneratedFilterBlock_states
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_DW.GeneratedFilterBlock_states_g
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 11;
	
	  ;% RaspPiPilot_DW.GeneratedFilterBlock_states_f
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 22;
	
	  ;% RaspPiPilot_DW.GeneratedFilterBlock_states_m
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 33;
	
	  ;% RaspPiPilot_DW.GeneratedFilterBlock_states_l
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 44;
	
	  ;% RaspPiPilot_DW.GeneratedFilterBlock_states_j
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 57;
	
	  ;% RaspPiPilot_DW.GeneratedFilterBlock_states_k
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 70;
	
	  ;% RaspPiPilot_DW.Memory_PreviousInput
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 83;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% RaspPiPilot_DW.Scope1_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_DW.Scope2_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RaspPiPilot_DW.Scope4_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RaspPiPilot_DW.Scope5_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% RaspPiPilot_DW.cond_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% RaspPiPilot_DW.idIn_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% RaspPiPilot_DW.idOut_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% RaspPiPilot_DW.itterator_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% RaspPiPilot_DW.length_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 8;
	
	  ;% RaspPiPilot_DW.msgId_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 9;
	
	  ;% RaspPiPilot_DW.Scope_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% RaspPiPilot_DW.Memory_PreviousInput_c
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_DW.Selector2_DIMS1
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RaspPiPilot_DW.Selector3_DIMS1
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 3;
	
	  ;% RaspPiPilot_DW.Selector4_DIMS1
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 5;
	
	  ;% RaspPiPilot_DW.BlobAnalysis2_WALKER_DW
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 7;
	
	  ;% RaspPiPilot_DW.BlobAnalysis1_WALKER_DW
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 15;
	
	  ;% RaspPiPilot_DW.BlobAnalysis1_WALKER_DW_b
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 23;
	
	  ;% RaspPiPilot_DW.SFunction_DIMS2
	  section.data(8).logicalSrcIdx = 26;
	  section.data(8).dtTransOffset = 31;
	
	  ;% RaspPiPilot_DW.SFunction_DIMS2_k
	  section.data(9).logicalSrcIdx = 27;
	  section.data(9).dtTransOffset = 33;
	
	  ;% RaspPiPilot_DW.SFunction_DIMS2_d
	  section.data(10).logicalSrcIdx = 28;
	  section.data(10).dtTransOffset = 35;
	
	  ;% RaspPiPilot_DW.spHandle
	  section.data(11).logicalSrcIdx = 29;
	  section.data(11).dtTransOffset = 37;
	
	  ;% RaspPiPilot_DW.sfEvent
	  section.data(12).logicalSrcIdx = 30;
	  section.data(12).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% RaspPiPilot_DW.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% RaspPiPilot_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% RaspPiPilot_DW.messageParser_SubsysRanBC
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_DW.Navigation_SubsysRanBC
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RaspPiPilot_DW.resultParser_SubsysRanBC
	  section.data(3).logicalSrcIdx = 35;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RaspPiPilot_DW.statusParser_SubsysRanBC
	  section.data(4).logicalSrcIdx = 36;
	  section.data(4).dtTransOffset = 3;
	
	  ;% RaspPiPilot_DW.statusParser1_SubsysRanBC
	  section.data(5).logicalSrcIdx = 37;
	  section.data(5).dtTransOffset = 4;
	
	  ;% RaspPiPilot_DW.stringParser_SubsysRanBC
	  section.data(6).logicalSrcIdx = 38;
	  section.data(6).dtTransOffset = 5;
	
	  ;% RaspPiPilot_DW.attitudeParser_SubsysRanBC
	  section.data(7).logicalSrcIdx = 39;
	  section.data(7).dtTransOffset = 6;
	
	  ;% RaspPiPilot_DW.RateTransition_semaphoreTaken
	  section.data(8).logicalSrcIdx = 40;
	  section.data(8).dtTransOffset = 7;
	
	  ;% RaspPiPilot_DW.RateTransition1_semaphoreTaken
	  section.data(9).logicalSrcIdx = 41;
	  section.data(9).dtTransOffset = 8;
	
	  ;% RaspPiPilot_DW.RateTransition2_semaphoreTaken
	  section.data(10).logicalSrcIdx = 42;
	  section.data(10).dtTransOffset = 9;
	
	  ;% RaspPiPilot_DW.FunctionCallSubsystem_SubsysRan
	  section.data(11).logicalSrcIdx = 43;
	  section.data(11).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% RaspPiPilot_DW.RateTransition_Buffer0
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_DW.RateTransition1_Buffer0
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 76800;
	
	  ;% RaspPiPilot_DW.RateTransition2_Buffer0
	  section.data(3).logicalSrcIdx = 46;
	  section.data(3).dtTransOffset = 153600;
	
	  ;% RaspPiPilot_DW.is_active_c5_RaspPiPilot
	  section.data(4).logicalSrcIdx = 47;
	  section.data(4).dtTransOffset = 230400;
	
	  ;% RaspPiPilot_DW.is_c5_RaspPiPilot
	  section.data(5).logicalSrcIdx = 48;
	  section.data(5).dtTransOffset = 230401;
	
	  ;% RaspPiPilot_DW.is_Disarmed
	  section.data(6).logicalSrcIdx = 49;
	  section.data(6).dtTransOffset = 230402;
	
	  ;% RaspPiPilot_DW.is_Armed
	  section.data(7).logicalSrcIdx = 50;
	  section.data(7).dtTransOffset = 230403;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% RaspPiPilot_DW.spHandle_not_empty
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RaspPiPilot_DW.isStable
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RaspPiPilot_DW.Navigation_MODE
	  section.data(3).logicalSrcIdx = 53;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2786906485;
  targMap.checksum1 = 544495020;
  targMap.checksum2 = 1268545206;
  targMap.checksum3 = 368425856;

