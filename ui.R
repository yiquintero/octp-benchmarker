library(shiny)
library(shinydashboard)

# Define User-interface definition for the Shiny web application.
ui <- dashboardPage(
      dashboardHeader(title = "Benchmarks for OCTP plugin for LAMMPS",
                      titleWidth = 250),
  
  ## Sidebar content  
  dashboardSidebar(width =  250,
    
    sidebarMenu(
      menuItem("Overview", tabName = "overview"),
      menuItem("Execution Time", tabName = "runtime"),
      menuItem("RAM Memory", tabName = "memory"),       
      menuItem("MPI", tabName = "mpi")
    )
  ),
  
  ## Body content
  dashboardBody(
    tabItems(
      
      # Overview tab content
      tabItem(tabName = "overview",
              h3("Description of benchmarking exercise"),
              br(),
              mainPanel(
                #plotOutput("bargraph", width =800)
              )
      ),   
      
      # Execition Time tab content
      tabItem(tabName = "runtime",
              h3("Wall-clock and Loop time"),
              #br(),
              mainPanel(
                plotOutput("runtime", width =800),
                plotOutput("looptime", width =800)
              )
      ),  
      
      # RAM Memory tab content
      tabItem(tabName = "memory"),
      
      # MPI tab content
      tabItem(tabName = "mpi",
              h1("LAMMPS Chart")          
        )    
    ),
    
    
    tags$head(tags$style(HTML('
                              /* logo */
                              .skin-blue .main-header .logo {
                              #  background-color: #f4b943;
                              background-color: purple;
                              }
                              
                              /* logo when hovered */
                              .skin-blue .main-header .logo:hover {
                              background-color: #f4b943;
                              }
                              
                              /* navbar (rest of the header) */
                              .skin-blue .main-header .navbar {
                              background-color: purple;
                              }        
                              
                              /* main sidebar */
                              .skin-blue .main-sidebar {
                              background-color: #cccccc;
                              }
                              
                              /* active selected tab in the sidebarmenu */
                              .skin-blue .main-sidebar .sidebar .sidebar-menu .active a{
                              background-color: #ff69b4;
                              }
                              
                              /* other links in the sidebarmenu */
                              .skin-blue .main-sidebar .sidebar .sidebar-menu a{
                              background-color: #c6e2ff;
                              color: #000000;
                              }
                              
                              /* other links in the sidebarmenu when hovered */
                              .skin-blue .main-sidebar .sidebar .sidebar-menu a:hover{
                              background-color: #ff69b4;
                              }
                              /* toggle button when hovered  */                    
                              .skin-blue .main-header .navbar .sidebar-toggle:hover{
                              background-color: #ff69b4;
                              }
                              ')))
    
  )   # end of dashboardBody
)    # end of dashboardPage
