library(shiny)
library(shinydashboard)
library(ggplot2)
library(dplyr)
library(tidyr)

# Import csv file
data <- read.csv("octpbenchmarkdata.csv")

################################################################################################
# server logic of the R Shiny web application
################################################################################################

# Define server logic of the R Shiny web application
server <- function(input, output) {

  output$runtime <- renderPlot ({
    plot(x = data$timesteps,
	      y = data$runtime,
	      xlab = "Simulation Time Steps",
	      ylab = "Seff - Wall-clock (mins)",
	      main = "Job Runtime - 512 particles",
        xaxt = "n", yaxt = "n")
    # x-axis
    axis(1, at = c(100000, 500000, 10000000, 5000000, 10000000, 25000000, 50000000),
        labels = c("100K", "500K", "1M", "5M", "10M", "25M", "50M"))
    # y-axis
    axis(2, at = c(30, 60, 300, 1800, 3600, 7200, 10800, 14400),
        labels = c("0.5", "1", "5", "30", "60", "120", "180", "240"))
  })

  output$looptime <- renderPlot ({
    plot(x = data$timesteps,
	      y = data$looptime,
	      xlab = "Simulation Time Steps",
	      ylab = "LAMMPS - Loop Iteration Time (s)",
	      main = "LAMMPS reported loop iteration time - 512 particles",
        xaxt = "n", yaxt = "n")
    # x-axis
    axis(1, at = c(100000, 500000, 10000000, 5000000, 10000000, 25000000, 50000000),
        labels = c("100K", "500K", "1M", "5M", "10M", "25M", "50M"))
    # y-axis
    axis(2, at = c(30, 60, 300, 1800, 3600, 7200, 10800, 14400),
        labels = c("0.5", "1", "5", "30", "60", "120", "180", "240"))
  })
  
  # output$bargraph <- renderPlot ({ 
  #   ggplot(df_view3, aes(Year, value/1000)) +   
  #     geom_bar(aes(fill = variable), position = "dodge", stat = "identity") +
  #     theme(panel.background = element_blank(), axis.line = element_line(colour = "black")) +
  #     theme(axis.text.x = element_text(face = "bold", size = 11),
  #           axis.text.y = element_text(face = "bold", size = 11)) +
  #     labs(title = "Number of Views or Creations Per Year", y ="Number of Projects Viewed in thousand")
  # })
  
  
  # output$bargraph2 <- renderPlot ({ 
  #   ggplot(data = df_view6, aes(x = Year, y = Projects_Viewed/1000, fill = Is_Remixed)) + 
  #     geom_bar(stat="identity") +
  #     theme(panel.background = element_blank(), axis.line = element_line(colour = "black")) +
  #     theme(axis.text.x = element_text(face = "bold", size = 11),
  #           axis.text.y = element_text(face = "bold", size = 11)) +
  #     labs(title = "Yearly Projects Viewed Grouped by Is Remixed", y ="Number of Projects Viewed in thousand")
  # })
  

  # output$histogram1 <- renderPlot ({ 
  #   hist(df_view$viewers_website, breaks = input$bins, col="sky blue",
  #        main="Histogram", xlab="Projects Viewed")})
  
  # output$histogram2 <- renderPlot ({ 
  #   hist(df_view$lovers_website, breaks = input$bins2, col="sky blue",
  #        main="Histogram", xlab="Projects Loved")})
  
  # output$histogram3 <- renderPlot ({ 
  #   hist(df_view$downloaders_website, breaks = input$bins3, col="sky blue",
  #        main="Histogram", xlab="Projects Downloaded")})
  
  
  # output$ScratchPlot <- renderPlot({  
  #   iX   <- as.numeric(input$var)  
  #   iY   <- as.numeric(input$var2)
  #   x    <- df_view1[, iX]
  #   y    <- df_view1[, iY]
  #   require(graphics)
    
  #   ggplot(df_view1, aes(x,y)) +
  #     geom_point(aes(colour = factor(Year)), size = 4) +
  #     theme(panel.background = element_blank(), axis.line = element_line(colour = "black")) +
  #     labs(title = "Scatter Plot") +
  #     xlab(paste("Total of", names(df_view1[iX]))) +
  #     ylab(paste("Total of", names(df_view1[iY]))) +
  #     geom_smooth(method = lm)  
    
  # })
  
  # output$ScratchLinePlot <- renderPlot({  
  #   iX   <- as.numeric(input$var_1)  
  #   iY   <- as.numeric(input$var_2) #
  #   x    <- df_view1[, iX]
  #   y    <- df_view1[, iY]
    
  #   require(graphics)
  #   ggplot(df_view1, 
  #          aes(x,y)) +
  #     #geom_point(aes(colour = factor(Year)), size = 4) +
  #     xlab(paste("Total of", names(df_view1[iX]))) +
  #     ylab(paste("Total of", names(df_view1[iY]))) +
  #     ggtitle("Line Chart") +
  #     geom_line() +
  #     geom_smooth(method = lm)  
  #    })
  
} 
