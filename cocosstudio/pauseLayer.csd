<GameFile>
  <PropertyGroup Name="pauseLayer" Type="Layer" ID="3dd0899b-984f-4f21-9cbb-9ee111f3f6e6" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Layer" Tag="132" ctype="GameLayerObjectData">
        <Size X="640.0000" Y="960.0000" />
        <Children>
          <AbstractNodeData Name="pauseBack_1" ActionTag="-722780584" Tag="133" IconVisible="False" LeftMargin="92.0000" RightMargin="92.0000" TopMargin="234.0000" BottomMargin="394.0000" ctype="SpriteObjectData">
            <Size X="456.0000" Y="332.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="320.0000" Y="560.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5833" />
            <PreSize X="0.7125" Y="0.3458" />
            <FileData Type="PlistSubImage" Path="pauseBack.png" Plist="pause.plist" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="resumeButton" ActionTag="-472008087" Tag="134" IconVisible="False" LeftMargin="260.0000" RightMargin="260.0000" TopMargin="484.5000" BottomMargin="364.5000" TouchEnable="True" FontSize="14" ButtonText="Button" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="90" Scale9Height="89" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="120.0000" Y="111.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="320.0000" Y="420.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.4375" />
            <PreSize X="0.1875" Y="0.1156" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="PlistSubImage" Path="resume.png" Plist="pause.plist" />
            <NormalFileData Type="PlistSubImage" Path="resume.png" Plist="pause.plist" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>