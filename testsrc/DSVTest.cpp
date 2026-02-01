#include <gtest/gtest.h>
#include "DSVWriter.h"
#include "StringDataSink.h"

TEST(DSVWriterTest, EmptyRowTest){
    std::shared_ptr<CStringDataSink> DataSink = std::make_shared<CStringDataSink>();
    CDSVWriter Writer(DataSink,',');

    EXPECT_TRUE(DataSink->String().empty());
    EXPECT_EQ(DataSink->String(),"");
    EXPECT_TRUE(Writer.WriteRow({}));
    EXPECT_EQ(DataSink->String(),"");

}


TEST(DSVWriterTest, SingleRowTest){
    std::shared_ptr<CStringDataSink> DataSink = std::make_shared<CStringDataSink>();
    CDSVWriter Writer(DataSink,',');

    EXPECT_TRUE(DataSink->String().empty());
    EXPECT_EQ(DataSink->String(),"");
    EXPECT_TRUE(Writer.WriteRow({"A","B","C"}));
    EXPECT_EQ(DataSink->String(),"A,B,C");

}

TEST(DSVWriterTest, DifferentDelimiterTest){
    std::shared_ptr<CStringDataSink> DataSink = std::make_shared<CStringDataSink>();
    CDSVWriter Writer(DataSink,'|');

    EXPECT_TRUE(DataSink->String().empty());
    EXPECT_TRUE(Writer.WriteRow({"A","B","C"}));
    EXPECT_EQ(DataSink->String(),"A|B|C");
}

TEST(DSVWriterTest, EmptyFieldTest){
    std::shared_ptr<CStringDataSink> DataSink = std::make_shared<CStringDataSink>();
    CDSVWriter Writer(DataSink,',');

    EXPECT_TRUE(Writer.WriteRow({"A","","C"}));
    EXPECT_EQ(DataSink->String(),"A,,C");
}

TEST(DSVWriterTest, SingleFieldTest){
    std::shared_ptr<CStringDataSink> DataSink = std::make_shared<CStringDataSink>();
    CDSVWriter Writer(DataSink,',');

    EXPECT_TRUE(Writer.WriteRow({"Hello"}));
    EXPECT_EQ(DataSink->String(),"Hello");
}

TEST(DSVWriterTest, MultipleWriteRowAppendTest){
    std::shared_ptr<CStringDataSink> DataSink = std::make_shared<CStringDataSink>();
    CDSVWriter Writer(DataSink,',');

    EXPECT_TRUE(Writer.WriteRow({"A","B"}));
    EXPECT_EQ(DataSink->String(),"A,B");

    EXPECT_TRUE(Writer.WriteRow({"1","2"}));
    EXPECT_EQ(DataSink->String(),"A,B1,2");
}